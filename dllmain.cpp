// dllmain.cpp : Defines the entry point for the DLL application.
#include "windows.h"
#include <string>
#pragma comment(lib, "detour/detours.lib")
#include "detour/detours.h" //standard detour lib
#include <vector>
using namespace std;
class UnexHack
{
public:
    char UnexLicense[6]; //0x0000
    char pad_0006[56]; //0x0006
}; //Size: 0x003E
class IpAdress
{
public:
    char Ipshow[13]; //0x0000
    char pad_000D[56]; //0x000D
};
class UnexTitle
{
public:
    char MenuTitle[90]; //0x0000
    char pad_005A[56]; //0x005A
}; //Size: 0x0092
UnexHack* RevealKey = (UnexHack*)((uintptr_t)GetModuleHandle(NULL) + 0x11A1A0); //0x76D9720
IpAdress* network = (IpAdress*)((uintptr_t)GetModuleHandle(NULL) + 0x11A710);
UnexTitle* MenuName = (UnexTitle*)((uintptr_t)GetModuleHandle(NULL) + 0x11A710);
uintptr_t* address = reinterpret_cast<uintptr_t*>(0x11A950); // Eid 


#include <regex>
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS = false
void nop_(PVOID address, int bytes) {
    DWORD d, ds;
    VirtualProtect(address, bytes, PAGE_EXECUTE_READWRITE, &d);
    memset(address, 0x90, bytes); 
    VirtualProtect(address, bytes, d, &ds);
}


void checkboxes()
{
    uintptr_t unexshit = (uintptr_t)(GetModuleHandle(NULL));
    *(bool*)(unexshit + 0x11AB38) = 1;
}




void bypasscheck()
{
    nop_(PVOID(GetModuleHandle(NULL) + 0x11AB38), 1);
    //nop_(PVOID(GetModuleHandle(NULL) + 0x7F3E5), 4);
    /*nop_(PVOID(GetModuleHandle(NULL) + 0x0), 0);
    nop_(PVOID(GetModuleHandle(NULL) + 0x0), 0);
    nop_(PVOID(GetModuleHandle(NULL) + 0x0), 0);
    nop_(PVOID(GetModuleHandle(NULL) + 0x0), 0);*/
}

typedef const char*(__fastcall* UnexLOL)(const char* title);
UnexLOL UnexMeme = (UnexLOL)((uintptr_t)GetModuleHandle(NULL) + 0x11AA58);
const char* __fastcall subUnex(const char* title) {
    if (title == "Unex Refline")
    {
        return UnexMeme("Cracked by Scopes#9999");
    }
    else
    {
        return UnexMeme("Unex Refline");
    }

}


int main()
{

    system("cls");
    std::string unex = MenuName->MenuTitle;
    std::string keylol = RevealKey->UnexLicense;
    std::string unexserverip = network->Ipshow;
    AllocConsole();
    freopen("CONOUT$", "w", stdout);



    std::cout << "Unex Bypassed by scopes & Diamond (again hehe)\n";
    std::cout << (std::string("License Key: " + keylol) + "\n");
    std::cout << (std::string("ServerIP: " + unexserverip) + "\n");

    return 0;
}




DWORD WINAPI ScopesIsKing()
{
    DetourTransactionBegin();
    DetourUpdateThread(GetCurrentThread());
    DetourAttach(&(LPVOID&)UnexMeme, &subUnex);
    DetourTransactionCommit();
    return 0;
}


BOOL APIENTRY DllMain( HMODULE hModule,DWORD  ul_reason_for_call,LPVOID lpReserved)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        main();
        CloseHandle(CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)ScopesIsKing, hModule, 0, nullptr));
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

