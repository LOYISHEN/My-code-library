//filename: fileTraversal.c
//author: PenG
//create time: 2018/12/25
//description: Provides a template for traversing through files 

#include <stdio.h>
#include <stdlib.h> 
#include <io.h>
#include <string.h>
#include <assert.h>

//拼接目录和文件名为全名，写到fullname中 
int jointPathAndFilename(char *fullname, char *path, char *filename)
{
	assert(NULL != fullname && NULL != path && NULL != filename);
	int pathLen = strlen(path);
	int filenameLen = strlen(filename);
	memcpy(fullname, path, pathLen);
	fullname[pathLen] = '\\';
	strcpy(&fullname[pathLen+1], filename);
	
	return 0;
}

//遍历查找文件，path后 
int fileTraversal(char *path, char *filename)
{
	struct _finddata_t fileinfo;
	long fileHandle;
	char *fullname = (char *)malloc(sizeof(char)*(strlen(path)+strlen(filename)+2));
	jointPathAndFilename(fullname, path, filename);
	
	if (-1 == (fileHandle = _findfirst(fullname, &fileinfo)))
	{
		printf("文件不存在");
		free(fullname);
		//TODO
		return -1;
	}
	free(fullname);
	//文件名为当前目录或上一目录 
	if (0 == strcmp(fileinfo.name, ".") || 0 == strcmp(fileinfo.name, ".."))
	{
		NULL;
		//TODO
	}
	//遍历到一个目录 
	else if (_A_SUBDIR == (_A_SUBDIR & fileinfo.attrib))
	{
		printf("找到一个目录：%s\n", fileinfo.name);
		char *t_path = (char *)malloc(sizeof(char)*(strlen(path)+strlen(fileinfo.name)+2));
		jointPathAndFilename(t_path, path, fileinfo.name);
		fileTraversal(t_path, filename);
		free(t_path);
		//TODO
	}
	//遍历到一个文件 
	else
	{
		printf("文件名为：%s，大小为：%d\n", fileinfo.name, fileinfo.size);
		//TODO
	}
	
	while (0 == _findnext(fileHandle, &fileinfo))
	{
		//文件名为当前目录或上一目录 
		if (0 == strcmp(fileinfo.name, ".") || 0 == strcmp(fileinfo.name, ".."))
		{
			continue;
		}
		//遍历到一个目录 
		else if (_A_SUBDIR == (_A_SUBDIR & fileinfo.attrib))
		{
			printf("找到一个目录：%s\n", fileinfo.name);
			char *t_path = (char *)malloc(sizeof(char)*(strlen(path)+strlen(fileinfo.name)+2));
			jointPathAndFilename(t_path, path, fileinfo.name);
			fileTraversal(t_path, filename);
			free(t_path);
			//TODO
		}
		//遍历到一个文件 
		else
		{
			printf("文件名为：%s，大小为：%d\n", fileinfo.name, fileinfo.size);
			//TODO
		}
	}
	
	_findclose(fileHandle);
} 

int main(void)
{
	
	fileTraversal("c:\\", "*.*");
	
	return 0;
}