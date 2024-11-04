// SPDX-License-Identifier: GPL-2.0
/*
 *  linux/fs/ext2_ljj/symlink.c
 *
 * Only fast symlinks left here - the rest is done by generic code. AV, 1999
 *
 * Copyright (C) 1992, 1993, 1994, 1995
 * Remy Card (card@masi.ibp.fr)
 * Laboratoire MASI - Institut Blaise Pascal
 * Universite Pierre et Marie Curie (Paris VI)
 *
 *  from
 *
 *  linux/fs/minix/symlink.c
 *
 *  Copyright (C) 1991, 1992  Linus Torvalds
 *
 *  ext2_ljj symlink handling code
 */

#include "ext2_ljj.h"
#include "xattr.h"

const struct inode_operations ext2_ljj_symlink_inode_operations = {
	.get_link	= page_get_link,
	.getattr	= ext2_ljj_getattr,
	.setattr	= ext2_ljj_setattr,
	.listxattr	= ext2_ljj_listxattr,
};
 
const struct inode_operations ext2_ljj_fast_symlink_inode_operations = {
	.get_link	= simple_get_link,
	.getattr	= ext2_ljj_getattr,
	.setattr	= ext2_ljj_setattr,
	.listxattr	= ext2_ljj_listxattr,
};
