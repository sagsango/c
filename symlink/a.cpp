#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>


// https://docs.huihoo.com/doxygen/linux/kernel/3.7/include_2uapi_2linux_2stat_8h.html
#ifdef S_IFMT
#undef S_IFMT
#endif

#ifdef S_IFLNK
#undef S_IFLNK
#endif

#ifdef S_ISLNK
#undef S_ISLNK
#endif

#define 	S_IFMT   	00170000	//00000000000011110000000000000000
#define 	S_IFLNK   	0120000		//00000000000001010000000000000000

#define 	S_ISLNK(m)	(((m) & S_IFMT) == S_IFLNK)


#define S statbuf 
struct stat statbuf;
char path[10][100] = {"./file.cpp", "./slink.cpp", "file_WOSL.cpp"};
const int n = 3;

void see(const char *api, const char * path ){
	printf("%8s(%15s) = st_dev[ %6d ], st_ino[ %6d ], st_mode[ %6d ], st_nlink[ %6d ], st_uid [ %6d ], st_guid [ %6d ], S_ISLNK[%1d]\n", api, path, S.st_dev, S.st_ino, S.st_mode, S.st_nlink, S.st_uid, S.st_gid, S_ISLNK( S.st_mode) );
}
int main(){
	
	for(int i=0;i<n;++i){
		if( lstat( path[i], &statbuf) != -1 ){
			see("lstat", path[i] );
		}
		if( stat( path[i], &statbuf) != -1 ){
			see("stat", path[i]);
		}
	}
}
