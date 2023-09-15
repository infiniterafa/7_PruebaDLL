#include <iostream>
#include <Windows.h>
//#include <string>

int main()
{
    puts("Loading...");
    HINSTANCE myDll = LoadLibrary(L"6_DLL.dll");
    if (myDll != NULL)
    {
        puts(":/");
        typedef const char* (*GetCodeFunc)();
        GetCodeFunc getCodename = reinterpret_cast<GetCodeFunc>(GetProcAddress(myDll, "GetCodename"));

        if (getCodename != NULL)
        {
            const char* msj = getCodename();
            std::cout << "desde la DLL: " << msj << "\n";
        }
        else
        {
            puts("Hmmmmmmm");
        }

        typedef double (*sumarFunc)(double a, double b);
        sumarFunc sumar = reinterpret_cast<sumarFunc>(GetProcAddress(myDll, "sumar"));
        if (sumar != NULL)
        {
            //double num = sumar(4, 7);
            std::cout << "desde la DLL: " << sumar(4, 7) << "\n";
        }
        else
        {
            puts("hmmmm");
        }

        typedef std::string (*stringFunc)(const std::string& a, const std::string& b);
        stringFunc strings = reinterpret_cast<stringFunc>(GetProcAddress(myDll, "ojo"));
        if (strings != NULL)
        {
            std::string s = "Hola,";
            std::string f = "todo bien? \n";
            std::cout << "desde la DLL: " << strings(s, f) << "\n";
        }
        else
        {
            puts("://");
        }

        FreeLibrary(myDll);
    }
    else
    {
        puts("Algo no está bien :/");
    }

    puts(":3");
    return 0;
}
