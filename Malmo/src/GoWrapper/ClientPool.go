// --------------------------------------------------------------------------------------------------
//  Copyright (c) 2016 Microsoft Corporation
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
//  associated documentation files (the "Software"), to deal in the Software without restriction,
//  including without limitation the rights to use, copy, modify, merge, publish, distribute,
//  sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in all copies or
//  substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
//  NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
//  NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
//  DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
// --------------------------------------------------------------------------------------------------

package malmo

/*
#include "x_client_pool.h"
#include "x_auxiliary.h"
*/
import "C"

// ClientPool defines a pool of expected network locations of Mod clients.
type ClientPool struct {
	pt  C.ptClientPool // pointer to C.ClientPool
	err *C.char        // buffer to hold error messages from C++
}

// NewClientPool ceates a ClientPool
func NewClientPool() (o *ClientPool) {
	o = new(ClientPool)
	o.pt = C.new_client_pool()
	o.err = C.make_buffer(C.CP_ERROR_BUFFER_SIZE)
	return
}

// Free deallocates ClientPool object
func (o *ClientPool) Free() {
	if o.pt != nil {
		C.free_client_pool(o.pt)
		C.free_buffer(o.err)
	}
}

// Add adds a client to the pool.
// client_info -- The client information.
func (o *ClientPool) Add(client_info *ClientInfo) {
	status := C.client_pool_add(o.pt, o.err, client_info.pt)
	if status != 0 {
		message := C.GoString(o.err)
		panic("ERROR:\n" + message)
	}
}
