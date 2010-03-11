/* radare - LGPL - Copyright 2009-2010 nibble<.ds@gmail.com> */

#include <r_types.h>
#include <r_util.h>
#include <r_bin.h>

/* XXX Implement r__bin_wr_scn_{set, del} instead */
R_API ut64 r_bin_wr_scn_resize(RBin *bin, const char *name, ut64 size) {
	if (bin && bin->cur && bin->cur->write && bin->cur->write->scn_resize)
		return bin->cur->write->scn_resize (bin, name, size);
	return R_FALSE;
}

R_API int r_bin_wr_output(RBin *bin, const char *filename) {
	if (!r_file_dump (filename, bin->buf->buf, bin->buf->length))
		return R_FALSE;
	return R_TRUE;
}
