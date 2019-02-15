//filename: fileTraversal.c
//author: PenG
//create time: 2018/12/25
//description: Provides a template for traversing through files 

#include <stdio.h>
#include <stdlib.h> 
#include <io.h>
#include <string.h>
#include <assert.h>

//ƴ��Ŀ¼���ļ���Ϊȫ����д��fullname�� 
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

//���������ļ���path�� 
int fileTraversal(char *path, char *filename)
{
	struct _finddata_t fileinfo;
	long fileHandle;
	char *fullname = (char *)malloc(sizeof(char)*(strlen(path)+strlen(filename)+2));
	jointPathAndFilename(fullname, path, filename);
	
	if (-1 == (fileHandle = _findfirst(fullname, &fileinfo)))
	{
		printf("�ļ�������");
		free(fullname);
		//TODO
		return -1;
	}
	free(fullname);
	//�ļ���Ϊ��ǰĿ¼����һĿ¼ 
	if (0 == strcmp(fileinfo.name, ".") || 0 == strcmp(fileinfo.name, ".."))
	{
		NULL;
		//TODO
	}
	//������һ��Ŀ¼ 
	else if (_A_SUBDIR == (_A_SUBDIR & fileinfo.attrib))
	{
		printf("�ҵ�һ��Ŀ¼��%s\n", fileinfo.name);
		char *t_path = (char *)malloc(sizeof(char)*(strlen(path)+strlen(fileinfo.name)+2));
		jointPathAndFilename(t_path, path, fileinfo.name);
		fileTraversal(t_path, filename);
		free(t_path);
		//TODO
	}
	//������һ���ļ� 
	else
	{
		printf("�ļ���Ϊ��%s����СΪ��%d\n", fileinfo.name, fileinfo.size);
		//TODO
	}
	
	while (0 == _findnext(fileHandle, &fileinfo))
	{
		//�ļ���Ϊ��ǰĿ¼����һĿ¼ 
		if (0 == strcmp(fileinfo.name, ".") || 0 == strcmp(fileinfo.name, ".."))
		{
			continue;
		}
		//������һ��Ŀ¼ 
		else if (_A_SUBDIR == (_A_SUBDIR & fileinfo.attrib))
		{
			printf("�ҵ�һ��Ŀ¼��%s\n", fileinfo.name);
			char *t_path = (char *)malloc(sizeof(char)*(strlen(path)+strlen(fileinfo.name)+2));
			jointPathAndFilename(t_path, path, fileinfo.name);
			fileTraversal(t_path, filename);
			free(t_path);
			//TODO
		}
		//������һ���ļ� 
		else
		{
			printf("�ļ���Ϊ��%s����СΪ��%d\n", fileinfo.name, fileinfo.size);
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