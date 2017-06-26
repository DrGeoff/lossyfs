/** A filesystem that deletes data rather than filling up.  */
#include "lfs_fuse.hpp"
#include <iostream>


int usage()
{
    std::cerr << "Usage:  lfs [FUSE and mount options] root_dir mount_point\n";
    return -1;
}


int main(int argc, char* argv[])
{
    if ((argc < 3) || (argv[argc - 2][0] == '-') || (argv[argc - 1][0] == '-'))
    {
        usage();
    }

    fuse_operations lfs_oper;

    lfs_oper.getattr  = lfs::getattr;
    lfs_oper.readlink = lfs::readlink;
    // no .getdir -- that's deprecated
    lfs_oper.getdir   = nullptr;
    lfs_oper.mknod    = lfs::mknod;
    lfs_oper.mkdir    = lfs::mkdir;
    lfs_oper.unlink   = lfs::unlink;
    lfs_oper.rmdir    = lfs::rmdir;
    lfs_oper.symlink  = lfs::symlink;
    lfs_oper.rename   = lfs::rename;
    lfs_oper.link     = lfs::link;
    lfs_oper.chmod    = lfs::chmod;
    lfs_oper.chown    = lfs::chown;
    lfs_oper.truncate = lfs::truncate;
    lfs_oper.utime    = lfs::utime;
    lfs_oper.open     = lfs::open;
    lfs_oper.read     = lfs::read;
    lfs_oper.write    = lfs::write;
    // Just a placeholder; don't set.  BBFS doesn't explain this.
    lfs_oper.statfs  = lfs::statfs;
    lfs_oper.flush   = lfs::flush;
    lfs_oper.release = lfs::release;
    lfs_oper.fsync   = lfs::fsync;

    lfs_oper.setxattr    = lfs::setxattr;
    lfs_oper.getxattr    = lfs::getxattr;
    lfs_oper.listxattr   = lfs::listxattr;
    lfs_oper.removexattr = lfs::removexattr;

    lfs_oper.opendir    = lfs::opendir;
    lfs_oper.readdir    = lfs::readdir;
    lfs_oper.releasedir = lfs::releasedir;
    lfs_oper.fsyncdir   = lfs::fsyncdir;
    lfs_oper.init       = lfs::init;
    lfs_oper.destroy    = lfs::destroy;
    lfs_oper.access     = lfs::access;
    lfs_oper.ftruncate  = lfs::ftruncate;
    lfs_oper.fgetattr   = lfs::fgetattr;

    return fuse_main(argc, argv, &lfs_oper, nullptr);
}
