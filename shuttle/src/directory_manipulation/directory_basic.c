//#include <libshuttle.h>
//#include <sys/types.h>
//#include <dirent.h>
//
//BOOL	check_file_presence(simple_list_t* names, int length)
//{
//        DIR*            dir;
//        struct dirent*  info;
//	int		found = 0;
//
//        dir = opendir(".");
//        info = readdir(dir);
//        while (info)
//        {
//                if (str_equals_any(info->d_name, names))
//		{
//			found++;
//			if (found == length)
//			{
//				closedir(dir);
//				return (1);
//			}
//		}
//                info = readdir(dir);
//        }
//        closedir(dir);
//	return (0);
//}
