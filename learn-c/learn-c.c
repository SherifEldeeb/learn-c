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
	URLDownloadToFileA(NULL, url, path, 0, NULL);

	return 0;
}