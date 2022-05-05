/********************************************************************************************
*    Copyright (c) 2022, by Jex.All rights reserved
*********************************************************************************************
*********************************************************************************************
  ** file name      : data_types.h
  ** purpose        : data typedef header file
  ** author         : JexJiang
  ** version        : v0.0.1
  ** compiler       : gcc
  ** created time   : 2022-5-5
  ** function list  :
*********************************************************************************************
  ** Note：
  ** Copyright (c) 2022 Jex.
  ** Revision History:
                   1.Date: 2022-5-5
                     Author: JexJiang
                     Modification: File created

*********************************************************************************************/


#ifndef  __DATA_TYPES_H__
#define  __DATA_TYPES_H__


#ifdef __cplusplus
extern "C" {
#endif 


#ifndef FALSE
    #define FALSE   0
#endif

#ifndef TRUE
    #define TRUE    1
#endif

#ifndef NULL
    #define NULL    0
#endif


typedef         unsigned char      	        boolean;
typedef         unsigned char               u8;
typedef         unsigned short              u16;
typedef         unsigned int                u32;
typedef         unsigned long               u64;
typedef         unsigned char               uint8;
typedef         unsigned short              uint16;
typedef         unsigned int                uint32;
typedef         unsigned long               uint64;
typedef         char                        s8;
typedef         short                       s16;
typedef         int                         s32;
typedef         long int                    s64;
typedef         char                        sint8;
typedef         short                       sint16;
typedef         int                         sint32;
typedef         long int                    sint64;
typedef         unsigned char      	        IBOOL;
typedef         char         		        INT8;
typedef         unsigned char               UINT8;
typedef         short        		        INT16;
typedef         unsigned short              UINT16;
typedef         int	         		        INT32;
typedef         unsigned int       	        UINT32;
typedef         long  				        INT64;
typedef         unsigned long  		        UINT64;
typedef         float  			            REAL32;
typedef         long double  		        REAL64;


#ifdef __cplusplus
}
#endif 


#endif


/********************************************************************************************
* (C) COPYRIGHT ShangHaiHeQian END OF FILE
*********************************************************************************************/
