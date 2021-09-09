#include <cstdio>
#include <cstdint>
#include <netinet/in.h>

uint32_t input(char* file) 
{
	FILE* fp=fopen(file,"rb");
	int BUF_SIZ=sizeof(uint32_t)/sizeof(uint8_t);
	uint8_t buf[BUF_SIZ];
	fread(buf,sizeof(uint8_t),BUF_SIZ,fp);
	uint32_t* p=reinterpret_cast<uint32_t*>(buf);
	fclose(fp);
	return ntohl(*p);
}

int main(int argc, char** argv)
{
	if(argc!=3) printf("Usage : ./add-nbo <file1> <file2>\n");
	else {
		int a=input(argv[1]);
		int b=input(argv[2]);
		int ans=a+b;
		printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n",a,a,b,b,ans,ans);
	}
	return 0;
}