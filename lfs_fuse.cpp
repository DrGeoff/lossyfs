#include "lfs_fuse.hpp"

namespace lfs {

int getattr(const char* path, struct stat* stbuf)
{
    int res = lstat(path, stbuf);
	if (res == -1)
		return -errno;

    return res;
}


int readlink(const char*, char*, size_t)
{
}


int getdir(const char*, fuse_dirh_t, fuse_dirfil_t)
{}

int mknod(const char*, mode_t, dev_t)
{
}


int mkdir(const char*, mode_t)
{
}


int unlink(const char*)
{
}


int rmdir(const char*)
{
}


int symlink(const char*, const char*)
{
}


int rename(const char*, const char*)
{
}


int link(const char*, const char*)
{
}


int chmod(const char*, mode_t)
{
}


int chown(const char*, uid_t, gid_t)
{
}


int truncate(const char*, off_t)
{
}


int utime(const char*, struct utimbuf*)
{
}


int open(const char*, struct fuse_file_info*)
{
}


int read(const char*, char*, size_t, off_t, struct fuse_file_info*)
{
}


int write(const char*, const char*, size_t, off_t, struct fuse_file_info*)
{
}


int statfs(const char*, struct statvfs*)
{
}


int flush(const char*, struct fuse_file_info*)
{
}


int release(const char*, struct fuse_file_info*)
{
}


int fsync(const char*, int, struct fuse_file_info*)
{
}


int setxattr(const char*, const char*, const char*, size_t, int)
{
}


int getxattr(const char*, const char*, char*, size_t)
{
}


int listxattr(const char*, char*, size_t)
{
}


int removexattr(const char*, const char*)
{
}


int opendir(const char*, struct fuse_file_info*)
{
}


int readdir(const char*, void*, fuse_fill_dir_t, off_t, struct fuse_file_info*)
{
}


int releasedir(const char*, struct fuse_file_info*)
{
}


int fsyncdir(const char*, int, struct fuse_file_info*)
{
}


void* init(struct fuse_conn_info* conn)
{
}


void destroy(void*)
{
}


int access(const char*, int)
{
}


int create(const char*, mode_t, struct fuse_file_info*)
{
}


int ftruncate(const char*, off_t, struct fuse_file_info*)
{
}


int fgetattr(const char*, struct stat*, struct fuse_file_info*)
{
}


int lock(const char*, struct fuse_file_info*, int cmd, struct flock*)
{
}


int utimens(const char*, const struct timespec tv[2])
{
}


int bmap(const char*, size_t blocksize, uint64_t* idx)
{
}


} // namespace ...
