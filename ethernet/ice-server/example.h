/* -*- mode: c; coding: utf-8 -*- */

#include <IceC/IceC.h>
#include <alloca.h>

typedef struct {
    Ice_Object __base;
} Example_Light;

typedef Example_Light* Example_LightPtr;

typedef Ice_ObjectPrx Example_LightPrx;
typedef Ice_ObjectPrx* Example_LightPrxPtr;

/* forward declaration */
static void
Example_Light_methodHandler(Example_LightPtr self,
                            Ice_InputStreamPtr is,
                            Ice_OutputStreamPtr os);

static void
Example_Light_init(Example_LightPtr self) {

    trace();
    
    Ice_Object_init((Ice_ObjectPtr)self,
            (Ice_MethodHandlerPtr)Example_Light_methodHandler);
}

void
Example_LightI_setState(Example_LightPtr self,
                        Ice_Bool state) __attribute__((weak));

static void
Example_Light_setState__dispatch(Example_LightPtr self,
                                 Ice_InputStreamPtr is,
                                 Ice_OutputStreamPtr os) {
    Ice_Bool state = 0;

    trace();
    
    Ice_InputStream_readBool(is, &state);
    
    Example_LightI_setState(self, state);
}

static void
Example_Light_methodHandler(Example_LightPtr self,
                            Ice_InputStreamPtr is,
                            Ice_OutputStreamPtr os) {
    Ice_Int operationSize = 0;
    char operation[MAX_OPERATION_NAME_SIZE];
    byte mode = 0;
    byte contextSize = 0;
    Ice_Int encapSize = 0;
    byte major = 0;
    byte minor = 0;

    trace();
    
    Ptr_check(self);
    Ptr_check(is);
    Ptr_check(os);
    
    Ice_InputStream_readSize(is, &operationSize, false);
    assert(operationSize <= MAX_OPERATION_NAME_SIZE);
    
    Ice_InputStream_readString(is, operation);
    
    /* FIXME: operationMode ignored */
    Ice_InputStream_readByte(is, &mode);
    
    /* FIXME: Context not supported */
    Ice_InputStream_readByte(is, &contextSize);
    assert(contextSize == 0);
    
    Ice_InputStream_readInt(is, &encapSize);
    Ice_InputStream_readByte(is, &major);
    Ice_InputStream_readByte(is, &minor);
    assert(major == 1 && minor == 0);
    assert(encapSize - 6 == (is->size - (is->next - is->data)));
    
    if (strcmp(operation, "setState") == 0) {
        Example_Light_setState__dispatch(self, is, os);
        return;
    }
    
    throw("Ice_OperationNotExistException", __FILE__, __LINE__);
}

static void
Example_Light_setState(Example_LightPrxPtr self,
                       Ice_Bool state) {
    Ice_OutputStreamPtr os = &(self->stream);

    trace();
    
    Ptr_check(self);
    
    Ice_ObjectPrx_connect(self);
    Ice_OutputStream_init(os);
    
    /* request header */
    Ice_OutputStream_writeBlob(os, Ice_header, sizeof(Ice_header));
    
    /* request body */
    Ice_OutputStream_writeInt(os, 0);
    Ice_OutputStream_writeIdentity(os, self->identity);
    Ice_OutputStream_writeString(os, "");
    Ice_OutputStream_writeString(os, "setState");
    Ice_OutputStream_writeByte(os, Ice_Normal);
    Ice_OutputStream_writeByte(os, 0);
    
    /* encapsulated params */
    Ice_OutputStream_startWriteEncaps(os);
    Ice_OutputStream_writeBool(os, state);
    Ice_OutputStream_endWriteEncaps(os);
    Ice_OutputStream_setMessageSize(os);
    
    Ice_ObjectPrx_send(self);
    
    /* FIXME: wait response and return correct value */
}

