#include <windows.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
	HANDLE hFile;
	DWORD dwBytesRead = 0;
	DWORD lpFileSizeLow;
	BYTE* buff;

	if (argc != 2) {
		printf("Incorrect number of args\n");
		return 1;
	}

	hFile = CreateFile(
		argv[1],
		GENERIC_READ,
		0,
		NULL,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL,
		NULL);
	
	if (hFile == INVALID_HANDLE_VALUE) {
		printf("something went wrong opening the file, does it exits?\n");
		return 2;
	}

	lpFileSizeLow = GetFileSize(hFile, NULL);

	if (lpFileSizeLow == INVALID_FILE_SIZE) {
		printf("Couldn't determine filesize ... will exit\n");
		return 3;
	}

	buff = (BYTE*)VirtualAlloc(NULL, lpFileSizeLow, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
	
	if (!ReadFile(hFile, buff, lpFileSizeLow, &dwBytesRead, NULL)) {
		printf("Something went wrong reading the file into the buffer ... will exit\n");
		return 4;
	}
	
	printf("We now have the \"%s\" file, with size '%d' loaded into memory address '0x%08X' ...\n", argv[1], lpFileSizeLow, buff);
	
	void (*x)();
	x = buff;
	x();
	//(*(void(*)()) buff)();

	return 0;

}