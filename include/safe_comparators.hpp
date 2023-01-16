#if !defined( __COMVIVA_UNO_10_C_SRC_MEM_MACRO_H__ )
#define __COMVIVA_UNO_10_C_SRC_MEM_MACRO_H__
/*!
  \def safe_cpy_len(_in_dest_max, _in_dest_cur, _in_src, _in_offset)
  returns how many 8-bit elements can be appended/ copied from \a _in_src into \a _in_dest.
*/
 
/*! 
   \brief Computes n 8-bit values from \a _in_src where 0<= n_safe_len <= length of \a _in_src.
    \param _in_dest_max maximum number of 8-bit elements that can be appended to destination memory.
    \param _in_dest_cur current number of 8-bit elements in destination memory.
    \param _in_src source memory.
    \param _in_offset offset leaves out the first \a _in_offset 8-bit elements from \a _in_src. MUST NOT be NEGATIVE.
   \returns count of 8-bit elements that can be appended/ copied from \a _in_src into \a _in_dest.
*/
#define safe_cpy_len(_in_dest_max_len, _in_dest_cur_len) \
    ( ((_in_dest_max_len) - (_in_dest_cur_len)) - 1 )

#define safe_min(a,b) \
    ({ typeof (a) _a = (a); \
       typeof (b) _b = (b); \
       _a < _b ? _a : _b; })

#endif // __COMVIVA_UNO_10_C_SRC_MEM_MACRO_H__