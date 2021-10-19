
#include <iostream>
#include <windows.h>
#include <fcntl.h>
#include <io.h>

#include "MemoryModule.h"

using namespace std;
int main()
{
    typedef void(*myfunc) ();
    HRSRC hRes = FindResource(NULL, TEXT("SIMPLEDLL"), RT_RCDATA);
    if (hRes == NULL) {
        cout << "Resource was not found" << endl;
    }
    else
    {
        HGLOBAL hGlobal = NULL;
        hGlobal = LoadResource(NULL, hRes);
        if (hGlobal != NULL) {
            DWORD dwFileSize = SizeofResource(NULL, hRes);
            HMEMORYMODULE handle = MemoryLoadLibrary(hGlobal, dwFileSize);
            if (handle != NULL) {
                myfunc func = (myfunc)MemoryGetProcAddress(handle, "func");
                if (func != NULL) {
                    func();
                }
                else {
                    cout << "functoin is null" << endl;
                }
            }
            else {
                cout << "handle is null" << endl;
            }  
        }
    }
    system("pause");
}