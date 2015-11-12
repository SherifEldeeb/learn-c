// learn-c.c : Defines the entry point for the console application.
//

#include <stdio.h>
#include <Urlmon.h>

int main()
{
	char url[] = "http://0up.me/file.txt";
	char path[] = "c:\\temp\\file.txt";

	printf("Url: %s will be saved to '%s'\n", url, path);

	// https://msdn.microsoft.com/en-us/library/ms775123(v=vs.85).aspx
	HRESULT result = URLDownloadToFileA(NULL, url, path, 0, NULL);

	if (result == S_OK) {
		printf("Ok\n");
	}
	else if (result == E_OUTOFMEMORY) {
		printf("Buffer length invalid, or insufficient memory\n");
	}
	else if (result == INET_E_DOWNLOAD_FAILURE) {
		printf("URL is invalid\n");
	}
	else {
		printf("Other error: %d\n", result);
	}

	return 0;
}