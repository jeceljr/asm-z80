
struct code_info {
    char * pattern ;
    char num_bytes , byte1 , byte2 , byte3 ;
    } table [] = {	"adc.a.,.(.hl.)." ,		1 , 0x8e , 0x00 , 0x00 ,
					"adc.a.,.(.ix.+.*.)." ,	2 , 0xdd , 0x8e , 0x00 ,
					"adc.a.,.(.iy.+.*.)." ,	2 , 0xfd , 0x8e , 0x00 ,
					"adc.a.,.a." ,			1 , 0x8f , 0x00 , 0x00 ,
					"adc.a.,.b." ,			1 , 0x88 , 0x00 , 0x00 ,
					"adc.a.,.c." ,			1 , 0x89 , 0x00 , 0x00 ,
					"adc.a.,.d." ,			1 , 0x8a , 0x00 , 0x00 ,
					"adc.a.,.e." ,			1 , 0x8b , 0x00 , 0x00 ,
					"adc.a.,.h." ,			1 , 0x8c , 0x00 , 0x00 ,
					"adc.a.,.l." ,			1 , 0x8d , 0x00 , 0x00 ,
					"adc.a.,.*." ,			1 , 0xce , 0x00 , 0x00 ,
					"adc.hl.,.bc." ,		2 , 0xed , 0x4a , 0x00 ,
					"adc.hl.,.de." ,		2 , 0xed , 0x5a , 0x00 ,
					"adc.hl.,.hl." ,		2 , 0xed , 0x6a , 0x00 ,
					"adc.hl.,.sp." ,		2 , 0xed , 0x7a , 0x00 ,
					"add.a.,.(.hl.)." ,		1 , 0x86 , 0x00 , 0x00 ,
					"add.a.,.(.ix.+.*.)." ,	2 , 0xdd , 0x86 , 0x00 ,
					"add.a.,.(.iy.+.*.)." ,	2 , 0xfd , 0x86 , 0x00 ,
					"add.a.,.a." ,			1 , 0x87 , 0x00 , 0x00 ,
					"add.a.,.b." ,			1 , 0x80 , 0x00 , 0x00 ,
					"add.a.,.c." ,			1 , 0x81 , 0x00 , 0x00 ,
					"add.a.,.d." ,			1 , 0x82 , 0x00 , 0x00 ,
					"add.a.,.e." ,			1 , 0x83 , 0x00 , 0x00 ,
					"add.a.,.h." ,			1 , 0x84 , 0x00 , 0x00 ,
					"add.a.,.l." ,			1 , 0x85 , 0x00 , 0x00 ,
					"add.a.,.*." ,			1 , 0xc6 , 0x00 , 0x00 ,
					"add.hl.,.bc." ,		1 , 0x09 , 0x00 , 0x00 ,
					"add.hl.,.de." ,		1 , 0x19 , 0x00 , 0x00 ,
					"add.hl.,.hl." ,		1 , 0x29 , 0x00 , 0x00 ,
					"add.hl.,.sp." ,		1 , 0x39 , 0x00 , 0x00 ,
					"add.ix.,.bc." ,		2 , 0xdd , 0x09 , 0x00 ,
					"add.ix.,.de." ,		2 , 0xdd , 0x19 , 0x00 ,
					"add.ix.,.hl." ,		2 , 0xdd , 0x29 , 0x00 ,
					"add.ix.,.sp." ,		2 , 0xdd , 0x39 , 0x00 ,
					"add.iy.,.bc." ,		2 , 0xfd , 0x09 , 0x00 ,
					"add.iy.,.de." ,		2 , 0xfd , 0x19 , 0x00 ,
					"add.iy.,.hl." ,		2 , 0xfd , 0x29 , 0x00 ,
					"add.iy.,.sp." ,		2 , 0xfd , 0x39 , 0x00 ,
					"and.(.hl.)." ,			1 , 0xa6 , 0x00 , 0x00 ,
					"and.(.ix.+.*.)." ,		2 , 0xdd , 0xa6 , 0x00 ,
					"and.(.iy.+.*.)." ,		2 , 0xfd , 0xa6 , 0x00 ,
					"and.a." ,				1 , 0xa7 , 0x00 , 0x00 ,
					"and.b." ,				1 , 0xa0 , 0x00 , 0x00 ,
					"and.c." ,				1 , 0xa1 , 0x00 , 0x00 ,
					"and.d." ,				1 , 0xa2 , 0x00 , 0x00 ,
					"and.e." ,				1 , 0xa3 , 0x00 , 0x00 ,
					"and.h." ,				1 , 0xa4 , 0x00 , 0x00 ,
					"and.l." ,				1 , 0xa5 , 0x00 , 0x00 ,
					"and.*." ,				1 , 0xe6 , 0x00 , 0x00 ,
					"bit.0.,.(.hl.)." ,		2 , 0xcb , 0x46 , 0x00 ,
					"bit.0.,.(.ix.+.*.)." ,	3 , 0xdd , 0xcb , 0x46 ,
					"bit.0.,.(.iy.+.*.)." ,	3 , 0xfd , 0xcb , 0x46 ,
					"bit.0.,.a." ,			2 , 0xcb , 0x47 , 0x00 ,
					"bit.0.,.b." ,			2 , 0xcb , 0x40 , 0x00 ,
					"bit.0.,.c." ,			2 , 0xcb , 0x41 , 0x00 ,
					"bit.0.,.d." ,			2 , 0xcb , 0x42 , 0x00 ,
					"bit.0.,.e." ,			2 , 0xcb , 0x43 , 0x00 ,
					"bit.0.,.h." ,			2 , 0xcb , 0x44 , 0x00 ,
					"bit.0.,.l." ,			2 , 0xcb , 0x45 , 0x00 ,
					"bit.1.,.(.hl.)." ,		2 , 0xcb , 0x4e , 0x00 ,
					"bit.1.,.(.ix.+.*.)." ,	3 , 0xdd , 0xcb , 0x4e ,
					"bit.1.,.(.iy.+.*.)." ,	3 , 0xfd , 0xcb , 0x4e ,
					"bit.1.,.a." ,			2 , 0xcb , 0x4f , 0x00 ,
					"bit.1.,.b." ,			2 , 0xcb , 0x48 , 0x00 ,
					"bit.1.,.c." ,			2 , 0xcb , 0x49 , 0x00 ,
					"bit.1.,.d." ,			2 , 0xcb , 0x4a , 0x00 ,
					"bit.1.,.e." ,			2 , 0xcb , 0x4b , 0x00 ,
					"bit.1.,.h." ,			2 , 0xcb , 0x4c , 0x00 ,
					"bit.1.,.l." ,			2 , 0xcb , 0x4d , 0x00 ,
					"bit.2.,.(.hl.)." ,		2 , 0xcb , 0x56 , 0x00 ,
					"bit.2.,.(.ix.+.*.)." ,	3 , 0xdd , 0xcb , 0x56 ,
					"bit.2.,.(.iy.+.*.)." ,	3 , 0xfd , 0xcb , 0x56 ,
					"bit.2.,.a." ,			2 , 0xcb , 0x57 , 0x00 ,
					"bit.2.,.b." ,			2 , 0xcb , 0x50 , 0x00 ,
					"bit.2.,.c." ,			2 , 0xcb , 0x51 , 0x00 ,
					"bit.2.,.d." ,			2 , 0xcb , 0x52 , 0x00 ,
					"bit.2.,.e." ,			2 , 0xcb , 0x53 , 0x00 ,
					"bit.2.,.h." ,			2 , 0xcb , 0x54 , 0x00 ,
					"bit.2.,.l." ,			2 , 0xcb , 0x55 , 0x00 ,
					"bit.3.,.(.hl.)." ,		2 , 0xcb , 0x5e , 0x00 ,
					"bit.3.,.(.ix.+.*.)." ,	3 , 0xdd , 0xcb , 0x5e ,
					"bit.3.,.(.iy.+.*.)." ,	3 , 0xfd , 0xcb , 0x5e ,
					"bit.3.,.a." ,			2 , 0xcb , 0x5f , 0x00 ,
					"bit.3.,.b." ,			2 , 0xcb , 0x58 , 0x00 ,
					"bit.3.,.c." ,			2 , 0xcb , 0x59 , 0x00 ,
					"bit.3.,.d." ,			2 , 0xcb , 0x5a , 0x00 ,
					"bit.3.,.e." ,			2 , 0xcb , 0x5b , 0x00 ,
					"bit.3.,.h." ,			2 , 0xcb , 0x5c , 0x00 ,
					"bit.3.,.l." ,			2 , 0xcb , 0x5d , 0x00 ,
					"bit.4.,.(.hl.)." ,		2 , 0xcb , 0x66 , 0x00 ,
					"bit.4.,.(.ix.+.*.)." ,	3 , 0xdd , 0xcb , 0x66 ,
					"bit.4.,.(.iy.+.*.)." ,	3 , 0xfd , 0xcb , 0x66 ,
					"bit.4.,.a." ,			2 , 0xcb , 0x67 , 0x00 ,
					"bit.4.,.b." ,			2 , 0xcb , 0x60 , 0x00 ,
					"bit.4.,.c." ,			2 , 0xcb , 0x61 , 0x00 ,
					"bit.4.,.d." ,			2 , 0xcb , 0x62 , 0x00 ,
					"bit.4.,.e." ,			2 , 0xcb , 0x63 , 0x00 ,
					"bit.4.,.h." ,			2 , 0xcb , 0x64 , 0x00 ,
					"bit.4.,.l." ,			2 , 0xcb , 0x65 , 0x00 ,
					"bit.5.,.(.hl.)." ,		2 , 0xcb , 0x6e , 0x00 ,
					"bit.5.,.(.ix.+.*.)." ,	3 , 0xdd , 0xcb , 0x6e ,
					"bit.5.,.(.iy.+.*.)." ,	3 , 0xfd , 0xcb , 0x6e ,
					"bit.5.,.a." ,			2 , 0xcb , 0x6f , 0x00 ,
					"bit.5.,.b." ,			2 , 0xcb , 0x68 , 0x00 ,
					"bit.5.,.c." ,			2 , 0xcb , 0x69 , 0x00 ,
					"bit.5.,.d." ,			2 , 0xcb , 0x6a , 0x00 ,
					"bit.5.,.e." ,			2 , 0xcb , 0x6b , 0x00 ,
					"bit.5.,.h." ,			2 , 0xcb , 0x6c , 0x00 ,
					"bit.5.,.l." ,			2 , 0xcb , 0x6d , 0x00 ,
					"bit.6.,.(.hl.)." ,		2 , 0xcb , 0x76 , 0x00 ,
					"bit.6.,.(.ix.+.*.)." ,	3 , 0xdd , 0xcb , 0x76 ,
					"bit.6.,.(.iy.+.*.)." ,	3 , 0xfd , 0xcb , 0x76 ,
					"bit.6.,.a." ,			2 , 0xcb , 0x77 , 0x00 ,
					"bit.6.,.b." ,			2 , 0xcb , 0x70 , 0x00 ,
					"bit.6.,.c." ,			2 , 0xcb , 0x71 , 0x00 ,
					"bit.6.,.d." ,			2 , 0xcb , 0x72 , 0x00 ,
					"bit.6.,.e." ,			2 , 0xcb , 0x73 , 0x00 ,
					"bit.6.,.h." ,			2 , 0xcb , 0x74 , 0x00 ,
					"bit.6.,.l." ,			2 , 0xcb , 0x75 , 0x00 ,
					"bit.7.,.(.hl.)." ,		2 , 0xcb , 0x7e , 0x00 ,
					"bit.7.,.(.ix.+.*.)." ,	3 , 0xdd , 0xcb , 0x7e ,
					"bit.7.,.(.iy.+.*.)." ,	3 , 0xfd , 0xcb , 0x7e ,
					"bit.7.,.a." ,			2 , 0xcb , 0x7f , 0x00 ,
					"bit.7.,.b." ,			2 , 0xcb , 0x78 , 0x00 ,
					"bit.7.,.c." ,			2 , 0xcb , 0x79 , 0x00 ,
					"bit.7.,.d." ,			2 , 0xcb , 0x7a , 0x00 ,
					"bit.7.,.e." ,			2 , 0xcb , 0x7b , 0x00 ,
					"bit.7.,.h." ,			2 , 0xcb , 0x7c , 0x00 ,
					"bit.7.,.l." ,			2 , 0xcb , 0x7d , 0x00 ,
					"call.c.,.@." ,			1 , 0xdc , 0x00 , 0x00 ,
					"call.m.,.@." ,			1 , 0xfc , 0x00 , 0x00 ,
					"call.nc.,.@." ,		1 , 0xd4 , 0x00 , 0x00 ,
					"call.nz.,.@." ,		1 , 0xc4 , 0x00 , 0x00 ,
					"call.p.,.@." ,			1 , 0xf4 , 0x00 , 0x00 ,
					"call.pe.,.@." ,		1 , 0xec , 0x00 , 0x00 ,
					"call.po.,.@." ,		1 , 0xe4 , 0x00 , 0x00 ,
					"call.z.,.@." ,			1 , 0xcc , 0x00 , 0x00 ,
					"call.@." ,				1 , 0xcd , 0x00 , 0x00 ,
					"ccf." ,				1 , 0x3f , 0x00 , 0x00 ,
					"cp.(.hl.)." ,			1 , 0xbe , 0x00 , 0x00 ,
					"cp.(.ix.+.*.)." ,		2 , 0xdd , 0xbe , 0x00 ,
					"cp.(.iy.+.*.)." ,		2 , 0xfd , 0xbe , 0x00 ,
					"cp.a." ,				1 , 0xbf , 0x00 , 0x00 ,
					"cp.b." ,				1 , 0xb8 , 0x00 , 0x00 ,
					"cp.c." ,				1 , 0xb9 , 0x00 , 0x00 ,
					"cpd." ,				2 , 0xed , 0xa9 , 0x00 ,
					"cp.d." ,				1 , 0xba , 0x00 , 0x00 ,
					"cp.e." ,				1 , 0xbb , 0x00 , 0x00 ,
					"cp.h." ,				1 , 0xbc , 0x00 , 0x00 ,
					"cpl." ,				1 , 0x2f , 0x00 , 0x00 ,
					"cp.l." ,				1 , 0xbd , 0x00 , 0x00 ,
					"cpdr." ,				2 , 0xed , 0xb9 , 0x00 ,
					"cpi." ,				2 , 0xed , 0xa1 , 0x00 ,
					"cpir." ,				2 , 0xed , 0xb1 , 0x00 ,
					"cp.*." ,				1 , 0xfe , 0x00 , 0x00 ,
					"daa." ,				1 , 0x27 , 0x00 , 0x00 ,
					"dec.(.hl.).",			1 , 0x35 , 0x00 , 0x00 ,
					"dec.(.ix.+.*.)." ,		2 , 0xdd , 0x35 , 0x00 ,
					"dec.(.iy.+.*.)." ,		2 , 0xfd , 0x35 , 0x00 ,
					"dec.a." ,				1 , 0x3d , 0x00 , 0x00 ,
					"dec.b." ,				1 , 0x05 , 0x00 , 0x00 ,
					"dec.bc." ,				1 , 0x0b , 0x00 , 0x00 ,
					"dec.c." ,				1 , 0x0d , 0x00 , 0x00 ,
					"dec.d." ,				1 , 0x15 , 0x00 , 0x00 ,
					"dec.de." ,				1 , 0x1b , 0x00 , 0x00 ,
					"dec.e." ,				1 , 0x1d , 0x00 , 0x00 ,
					"dec.h." ,				1 , 0x25 , 0x00 , 0x00 ,
					"dec.hl." ,				1 , 0x2b , 0x00 , 0x00 ,
					"dec.ix." ,				2 , 0xdd , 0x2b , 0x00 ,
					"dec.iy." ,				2 , 0xfd , 0x2b , 0x00 ,
					"dec.l." ,				1 , 0x2d , 0x00 , 0x00 ,
					"dec.sp." ,				1 , 0x3b , 0x00 , 0x00 ,
					"di." ,					1 , 0xf3 , 0x00 , 0x00 ,
					"djnz.?." ,				1 , 0x10 , 0x00 , 0x00 ,
					"ei." ,					1 , 0xfb , 0x00 , 0x00 ,
					"ex.(.sp.).,.hl." ,		1 , 0xe3 , 0x00 , 0x00 ,
					"ex.(.sp.).,.ix." ,		2 , 0xdd , 0xe3 , 0x00 ,
					"ex.(.sp.).,.iy." ,		2 , 0xfd , 0xe3 , 0x00 ,
					"ex.af.,.af'." ,		1 , 0x08 , 0x00 , 0x00 ,
					"ex.de.,.hl." ,			1 , 0xeb , 0x00 , 0x00 ,
					"exx." ,				1 , 0xd9 , 0x00 , 0x00 ,
					"halt." ,				1 , 0x76 , 0x00 , 0x00 ,
					"im.0." ,				2 , 0xed , 0x46 , 0x00 ,
					"im.1." ,				2 , 0xed , 0x56 , 0x00 ,
					"im.2." ,				2 , 0xed , 0x5e , 0x00 ,
					"in.a.,.(.c.)." ,		2 , 0xed , 0x78 , 0x00 ,
					"in.a.,.(.*.)." ,		1 , 0xdb , 0x00 , 0x00 ,
					"in.b.,.(.c.)." ,		2 , 0xed , 0x40 , 0x00 ,
					"in.c.,.(.c.)." ,		2 , 0xed , 0x48 , 0x00 ,
					"in.d.,.(.c.)." ,		2 , 0xed , 0x50 , 0x00 ,
					"in.e.,.(.c.)." ,		2 , 0xed , 0x58 , 0x00 ,
					"in.h.,.(.c.)." ,		2 , 0xed , 0x60 , 0x00 ,
					"in.l.,.(.c.)." ,		2 , 0xed , 0x68 , 0x00 ,
					"inc.(.hl.).",			1 , 0x34 , 0x00 , 0x00 ,
					"inc.(.ix.+.*.)." ,		2 , 0xdd , 0x34 , 0x00 ,
					"inc.(.iy.+.*.)." ,		2 , 0xfd , 0x34 , 0x00 ,
					"inc.a." ,				1 , 0x3c , 0x00 , 0x00 ,
					"inc.b." ,				1 , 0x04 , 0x00 , 0x00 ,
					"inc.bc." ,				1 , 0x03 , 0x00 , 0x00 ,
					"inc.c." ,				1 , 0x0c , 0x00 , 0x00 ,
					"inc.d." ,				1 , 0x14 , 0x00 , 0x00 ,
					"inc.de." ,				1 , 0x13 , 0x00 , 0x00 ,
					"inc.e." ,				1 , 0x1c , 0x00 , 0x00 ,
					"inc.h." ,				1 , 0x24 , 0x00 , 0x00 ,
					"inc.hl." ,				1 , 0x23 , 0x00 , 0x00 ,
					"inc.ix." ,				2 , 0xdd , 0x23 , 0x00 ,
					"inc.iy." ,				2 , 0xfd , 0x23 , 0x00 ,
					"inc.l." ,				1 , 0x2c , 0x00 , 0x00 ,
					"inc.sp." ,				1 , 0x33 , 0x00 , 0x00 ,
					"ind." ,				2 , 0xed , 0xaa , 0x00 ,
					"indr." ,				2 , 0xed , 0xba , 0x00 ,
					"ini." ,				2 , 0xed , 0xa2 , 0x00 ,
					"inir." ,				2 , 0xed , 0xb2 , 0x00 ,
					"jp.(.hl.)." ,			1 , 0xe9 , 0x00 , 0x00 ,
					"jp.(.ix.)." ,			2 , 0xdd , 0xe9 , 0x00 ,
					"jp.(.iy.)." ,			2 , 0xfd , 0xe9 , 0x00 ,
					"jp.c.,.@." ,			1 , 0xda , 0x00 , 0x00 ,
					"jp.m.,.@." ,			1 , 0xfa , 0x00 , 0x00 ,
					"jp.nc.,.@." ,			1 , 0xd2 , 0x00 , 0x00 ,
					"jp.nz.,.@." ,			1 , 0xc2 , 0x00 , 0x00 ,
					"jp.p.,.@." ,			1 , 0xf2 , 0x00 , 0x00 ,
					"jp.pe.,.@." ,			1 , 0xea , 0x00 , 0x00 ,
					"jp.po.,.@." ,			1 , 0xe2 , 0x00 , 0x00 ,
					"jp.z.,.@." ,			1 , 0xca , 0x00 , 0x00 ,
 					"jp.@." ,				1 , 0xc3 , 0x00 , 0x00 ,
					"jr.c.,.?." ,			1 , 0x38 , 0x00 , 0x00 ,
					"jr.nc.,.?." ,			1 , 0x30 , 0x00 , 0x00 ,
					"jr.nz.,.?." ,			1 , 0x20 , 0x00 , 0x00 ,
					"jr.z.,.?." ,			1 , 0x28 , 0x00 , 0x00 ,
					"jr.?." ,				1 , 0x18 , 0x00 , 0x00 ,
					"ld.(.bc.).,.a." ,		1 , 0x02 , 0x00 , 0x00 ,
					"ld.(.de.).,.a." ,		1 , 0x12 , 0x00 , 0x00 ,
					"ld.(.hl.).,.a." ,		1 , 0x77 , 0x00 , 0x00 ,
					"ld.(.hl.).,.b." ,		1 , 0x70 , 0x00 , 0x00 ,
					"ld.(.hl.).,.c." ,		1 , 0x71 , 0x00 , 0x00 ,
					"ld.(.hl.).,.d." ,		1 , 0x72 , 0x00 , 0x00 ,
					"ld.(.hl.).,.e." ,		1 , 0x73 , 0x00 , 0x00 ,
					"ld.(.hl.).,.h." ,		1 , 0x74 , 0x00 , 0x00 ,
					"ld.(.hl.).,.l." ,		1 , 0x75 , 0x00 , 0x00 ,
					"ld.(.hl.).,.*." ,		1 , 0x36 , 0x00 , 0x00 ,
					"ld.(.ix.+.*.).,.a." ,	2 , 0xdd , 0x77 , 0x00 ,
					"ld.(.ix.+.*.).,.b." ,	2 , 0xdd , 0x70 , 0x00 ,
					"ld.(.ix.+.*.).,.c." ,	2 , 0xdd , 0x71 , 0x00 ,
					"ld.(.ix.+.*.).,.d." ,	2 , 0xdd , 0x72 , 0x00 ,
					"ld.(.ix.+.*.).,.e." ,	2 , 0xdd , 0x73 , 0x00 ,
					"ld.(.ix.+.*.).,.h." ,	2 , 0xdd , 0x74 , 0x00 ,
					"ld.(.ix.+.*.).,.l." ,	2 , 0xdd , 0x75 , 0x00 ,
					"ld.(.ix.+.*.).,.*." ,	2 , 0xdd , 0x36 , 0x00 ,
					"ld.(.iy.+.*.).,.a." ,	2 , 0xfd , 0x77 , 0x00 ,
					"ld.(.iy.+.*.).,.b." ,	2 , 0xfd , 0x70 , 0x00 ,
					"ld.(.iy.+.*.).,.c." ,	2 , 0xfd , 0x71 , 0x00 ,
					"ld.(.iy.+.*.).,.d." ,	2 , 0xfd , 0x72 , 0x00 ,
					"ld.(.iy.+.*.).,.e." ,	2 , 0xfd , 0x73 , 0x00 ,
					"ld.(.iy.+.*.).,.h." ,	2 , 0xfd , 0x74 , 0x00 ,
					"ld.(.iy.+.*.).,.l." ,	2 , 0xfd , 0x75 , 0x00 ,
					"ld.(.iy.+.*.).,.*." ,	2 , 0xfd , 0x36 , 0x00 ,
					"ld.(.@.).,.a." ,		1 , 0x32 , 0x00 , 0x00 ,
					"ld.(.@.).,.bc." ,		2 , 0xed , 0x43 , 0x00 ,
					"ld.(.@.).,.de." ,		2 , 0xed , 0x53 , 0x00 ,
					"ld.(.@.).,.hl." ,		1 , 0x22 , 0x00 , 0x00 ,
					"ld.(.@.).,.ix." ,		2 , 0xdd , 0x22 , 0x00 ,
					"ld.(.@.).,.iy." ,		2 , 0xfd , 0x22 , 0x00 ,
					"ld.(.@.).,.sp." ,		2 , 0xed , 0x73 , 0x00 ,
					"ld.a.,.(.bc.)." ,		1 , 0x0a , 0x00 , 0x00 ,
					"ld.a.,.(.de.)." ,		1 , 0x1a , 0x00 , 0x00 ,
					"ld.a.,.(.hl.)." ,		1 , 0x7e , 0x00 , 0x00 ,
					"ld.a.,.(.ix.+.*.)." ,	2 , 0xdd , 0x7e , 0x00 ,
					"ld.a.,.(.iy.+.*.)." ,	2 , 0xfd , 0x7e , 0x00 ,
					"ld.a.,.(.@.)." ,		1 , 0x3a , 0x00 , 0x00 ,
					"ld.a.,.a." ,			1 , 0x7f , 0x00 , 0x00 ,
					"ld.a.,.b." ,			1 , 0x78 , 0x00 , 0x00 ,
					"ld.a.,.c." ,			1 , 0x79 , 0x00 , 0x00 ,
					"ld.a.,.d." ,			1 , 0x7a , 0x00 , 0x00 ,
					"ld.a.,.e." ,			1 , 0x7b , 0x00 , 0x00 ,
					"ld.a.,.h." ,			1 , 0x7c , 0x00 , 0x00 ,
					"ld.a.,.i." ,			2 , 0xed , 0x57 , 0x00 ,
					"ld.a.,.r." ,			2 , 0xed , 0x5f , 0x00 ,
					"ld.a.,.l." ,			1 , 0x7d , 0x00 , 0x00 ,
					"ld.a.,.*." ,			1 , 0x3e , 0x00 , 0x00 ,
					"ld.b.,.(.hl.)." ,		1 , 0x46 , 0x00 , 0x00 ,
					"ld.b.,.(.ix.+.*.)." ,	2 , 0xdd , 0x46 , 0x00 ,
					"ld.b.,.(.iy.+.*.)." ,	2 , 0xfd , 0x46 , 0x00 ,
					"ld.b.,.a." ,			1 , 0x47 , 0x00 , 0x00 ,
					"ld.b.,.b." ,			1 , 0x40 , 0x00 , 0x00 ,
					"ld.b.,.c." ,			1 , 0x41 , 0x00 , 0x00 ,
					"ld.b.,.d." ,			1 , 0x42 , 0x00 , 0x00 ,
					"ld.b.,.e." ,			1 , 0x43 , 0x00 , 0x00 ,
					"ld.b.,.h." ,			1 , 0x44 , 0x00 , 0x00 ,
					"ld.b.,.l." ,			1 , 0x45 , 0x00 , 0x00 ,
					"ld.b.,.*." ,			1 , 0x06 , 0x00 , 0x00 ,
					"ld.bc.,.(.@.)." ,		2 , 0xed , 0x4b , 0x00 ,
					"ld.bc.,.@." ,			1 , 0x01 , 0x00 , 0x00 ,
					"ld.c.,.(.hl.)." ,		1 , 0x4e , 0x00 , 0x00 ,
					"ld.c.,.(.ix.+.*.)." ,	2 , 0xdd , 0x4e , 0x00 ,
					"ld.c.,.(.iy.+.*.)." ,	2 , 0xfd , 0x4e , 0x00 ,
					"ld.c.,.a." ,			1 , 0x4f , 0x00 , 0x00 ,
					"ld.c.,.b." ,			1 , 0x48 , 0x00 , 0x00 ,
					"ld.c.,.c." ,			1 , 0x49 , 0x00 , 0x00 ,
					"ld.c.,.d." ,			1 , 0x4a , 0x00 , 0x00 ,
					"ld.c.,.e." ,			1 , 0x4b , 0x00 , 0x00 ,
					"ld.c.,.h." ,			1 , 0x4c , 0x00 , 0x00 ,
					"ld.c.,.l." ,			1 , 0x4d , 0x00 , 0x00 ,
					"ld.c.,.*." ,			1 , 0x0e , 0x00 , 0x00 ,
					"ld.d.,.(.hl.)." ,		1 , 0x56 , 0x00 , 0x00 ,
					"ld.d.,.(.ix.+.*.)." ,	2 , 0xdd , 0x56 , 0x00 ,
					"ld.d.,.(.iy.+.*.)." ,	2 , 0xfd , 0x56 , 0x00 ,
					"ld.d.,.a." ,			1 , 0x57 , 0x00 , 0x00 ,
					"ld.d.,.b." ,			1 , 0x50 , 0x00 , 0x00 ,
					"ld.d.,.c." ,			1 , 0x51 , 0x00 , 0x00 ,
					"ld.d.,.d." ,			1 , 0x52 , 0x00 , 0x00 ,
					"ld.d.,.e." ,			1 , 0x53 , 0x00 , 0x00 ,
					"ld.d.,.h." ,			1 , 0x54 , 0x00 , 0x00 ,
					"ld.d.,.l." ,			1 , 0x55 , 0x00 , 0x00 ,
					"ld.d.,.*." ,			1 , 0x16 , 0x00 , 0x00 ,
					"ld.de.,.(.@.)." ,		2 , 0xed , 0x5b , 0x00 ,
					"ld.de.,.@." ,			1 , 0x11 , 0x00 , 0x00 ,
					"ld.e.,.(.hl.)." ,		1 , 0x5e , 0x00 , 0x00 ,
					"ld.e.,.(.ix.+.*.)." ,	2 , 0xdd , 0x5e , 0x00 ,
					"ld.e.,.(.iy.+.*.)." ,	2 , 0xfd , 0x5e , 0x00 ,
					"ld.e.,.a." ,			1 , 0x5f , 0x00 , 0x00 ,
					"ld.e.,.b." ,			1 , 0x58 , 0x00 , 0x00 ,
					"ld.e.,.c." ,			1 , 0x59 , 0x00 , 0x00 ,
					"ld.e.,.d." ,			1 , 0x5a , 0x00 , 0x00 ,
					"ld.e.,.e." ,			1 , 0x5b , 0x00 , 0x00 ,
					"ld.e.,.h." ,			1 , 0x5c , 0x00 , 0x00 ,
					"ld.e.,.l." ,			1 , 0x5d , 0x00 , 0x00 ,
					"ld.e.,.*." ,			1 , 0x1e , 0x00 , 0x00 ,
					"ld.h.,.(.hl.)." ,		1 , 0x66 , 0x00 , 0x00 ,
					"ld.h.,.(.ix.+.*.)." ,	2 , 0xdd , 0x66 , 0x00 ,
					"ld.h.,.(.iy.+.*.)." ,	2 , 0xfd , 0x66 , 0x00 ,
					"ld.h.,.a." ,			1 , 0x67 , 0x00 , 0x00 ,
					"ld.h.,.b." ,			1 , 0x60 , 0x00 , 0x00 ,
					"ld.h.,.c." ,			1 , 0x61 , 0x00 , 0x00 ,
					"ld.h.,.d." ,			1 , 0x62 , 0x00 , 0x00 ,
					"ld.h.,.e." ,			1 , 0x63 , 0x00 , 0x00 ,
					"ld.h.,.h." ,			1 , 0x64 , 0x00 , 0x00 ,
					"ld.h.,.l." ,			1 , 0x65 , 0x00 , 0x00 ,
					"ld.h.,.*." ,			1 , 0x26 , 0x00 , 0x00 ,
					"ld.hl.,.(.@.)." ,		1 , 0x2a , 0x00 , 0x00 ,
					"ld.hl.,.@." ,			1 , 0x21 , 0x00 , 0x00 ,
					"ld.i.,.a." ,			2 , 0xed , 0x47 , 0x00 ,
					"ld.r.,.a." ,			2 , 0xed , 0x4f , 0x00 ,
					"ld.ix.,.(.@.)." ,		2 , 0xdd , 0x2a , 0x00 ,
					"ld.ix.,.@." ,			2 , 0xdd , 0x21 , 0x00 ,
					"ld.iy.,.(.@.)." ,		2 , 0xfd , 0x2a , 0x00 ,
					"ld.iy.,.@." ,			2 , 0xfd , 0x21 , 0x00 ,
					"ld.l.,.(.hl.)." ,		1 , 0x6e , 0x00 , 0x00 ,
					"ld.l.,.(.ix.+.*.)." ,	2 , 0xdd , 0x6e , 0x00 ,
					"ld.l.,.(.iy.+.*.)." ,	2 , 0xfd , 0x6e , 0x00 ,
					"ld.l.,.a." ,			1 , 0x6f , 0x00 , 0x00 ,
					"ld.l.,.b." ,			1 , 0x68 , 0x00 , 0x00 ,
					"ld.l.,.c." ,			1 , 0x69 , 0x00 , 0x00 ,
					"ld.l.,.d." ,			1 , 0x6a , 0x00 , 0x00 ,
					"ld.l.,.e." ,			1 , 0x6b , 0x00 , 0x00 ,
					"ld.l.,.h." ,			1 , 0x6c , 0x00 , 0x00 ,
					"ld.l.,.l." ,			1 , 0x6d , 0x00 , 0x00 ,
					"ld.l.,.*." ,			1 , 0x2e , 0x00 , 0x00 ,
					"ld.sp.,.(.@.)." ,		2 , 0xed , 0x7b , 0x00 ,
					"ld.sp.,.hl." ,			1 , 0xf9 , 0x00 , 0x00 ,
					"ld.sp.,.ix." ,			2 , 0xdd , 0xf9 , 0x00 ,
					"ld.sp.,.iy." ,			2 , 0xfd , 0xf9 , 0x00 ,
					"ld.sp.,.@." ,			1 , 0x31 , 0x00 , 0x00 ,
					"ldd." ,				2 , 0xed , 0xa8 , 0x00 ,
					"lddr." ,				2 , 0xed , 0xb8 , 0x00 ,
					"ldi." ,				2 , 0xed , 0xa0 , 0x00 ,
					"ldir." ,				2 , 0xed , 0xb0 , 0x00 ,
					"neg." ,				2 , 0xed , 0x44 , 0x00 ,
					"nop." ,				1 , 0x00 , 0x00 , 0x00 ,
					"or.(.hl.)." ,			1 , 0xb6 , 0x00 , 0x00 ,
					"or.(.ix.+.*.)." ,		2 , 0xdd , 0xb6 , 0x00 ,
					"or.(.iy.+.*.)." ,		2 , 0xfd , 0xb6 , 0x00 ,
					"or.a." ,				1 , 0xb7 , 0x00 , 0x00 ,
					"or.b." ,				1 , 0xb0 , 0x00 , 0x00 ,
					"or.c." ,				1 , 0xb1 , 0x00 , 0x00 ,
					"or.d." ,				1 , 0xb2 , 0x00 , 0x00 ,
					"or.e." ,				1 , 0xb3 , 0x00 , 0x00 ,
					"or.h." ,				1 , 0xb4 , 0x00 , 0x00 ,
					"or.l." ,				1 , 0xb5 , 0x00 , 0x00 ,
					"or.*." ,				1 , 0xf6 , 0x00 , 0x00 ,
					"otdr." ,				2 , 0xed , 0xbb , 0x00 ,
					"otir." ,				2 , 0xed , 0xb3 , 0x00 ,
					"out.(.c.).,.a." ,		2 , 0xed , 0x79 , 0x00 ,
					"out.(.c.).,.b." ,		2 , 0xed , 0x41 , 0x00 ,
					"out.(.c.).,.c." ,		2 , 0xed , 0x49 , 0x00 ,
					"out.(.c.).,.d." ,		2 , 0xed , 0x51 , 0x00 ,
					"out.(.c.).,.e." ,		2 , 0xed , 0x59 , 0x00 ,
					"out.(.c.).,.h." ,		2 , 0xed , 0x61 , 0x00 ,
					"out.(.c.).,.l." ,		2 , 0xed , 0x69 , 0x00 ,
					"out.(.*.).,.a." ,		1 , 0xd3 , 0x00 , 0x00 ,
					"outd." ,				2 , 0xed , 0xab , 0x00 ,
					"outi." ,				2 , 0xed , 0xa3 , 0x00 ,
					"pop.af." ,				1 , 0xf1 , 0x00 , 0x00 ,
					"pop.bc." ,				1 , 0xc1 , 0x00 , 0x00 ,
					"pop.de." ,				1 , 0xd1 , 0x00 , 0x00 ,
					"pop.hl." ,				1 , 0xe1 , 0x00 , 0x00 ,
					"pop.ix." ,				2 , 0xdd , 0xe1 , 0x00 ,
					"pop.iy." ,				2 , 0xfd , 0xe1 , 0x00 ,
					"push.af." ,			1 , 0xf5 , 0x00 , 0x00 ,
					"push.bc." ,			1 , 0xc5 , 0x00 , 0x00 ,
					"push.de." ,			1 , 0xd5 , 0x00 , 0x00 ,
					"push.hl." ,			1 , 0xe5 , 0x00 , 0x00 ,
					"push.ix." ,			2 , 0xdd , 0xe5 , 0x00 ,
					"push.iy." ,			2 , 0xfd , 0xe5 , 0x00 ,
					"res.0.,.(.hl.)." ,		2 , 0xcb , 0x86 , 0x00 ,
					"res.0.,.(.ix.+.*.)." ,	3 , 0xdd , 0xcb , 0x86 ,
					"res.0.,.(.iy.+.*.)." ,	3 , 0xfd , 0xcb , 0x86 ,
					"res.0.,.a." ,			2 , 0xcb , 0x87 , 0x00 ,
					"res.0.,.b." ,			2 , 0xcb , 0x80 , 0x00 ,
					"res.0.,.c." ,			2 , 0xcb , 0x81 , 0x00 ,
					"res.0.,.d." ,			2 , 0xcb , 0x82 , 0x00 ,
					"res.0.,.e." ,			2 , 0xcb , 0x83 , 0x00 ,
					"res.0.,.h." ,			2 , 0xcb , 0x84 , 0x00 ,
					"res.0.,.l." ,			2 , 0xcb , 0x85 , 0x00 ,
					"res.1.,.(.hl.)." ,		2 , 0xcb , 0x8e , 0x00 ,
					"res.1.,.(.ix.+.*.)." ,	3 , 0xdd , 0xcb , 0x8e ,
					"res.1.,.(.iy.+.*.)." ,	3 , 0xfd , 0xcb , 0x8e ,
					"res.1.,.a." ,			2 , 0xcb , 0x8f , 0x00 ,
					"res.1.,.b." ,			2 , 0xcb , 0x88 , 0x00 ,
					"res.1.,.c." ,			2 , 0xcb , 0x89 , 0x00 ,
					"res.1.,.d." ,			2 , 0xcb , 0x8a , 0x00 ,
					"res.1.,.e." ,			2 , 0xcb , 0x8b , 0x00 ,
					"res.1.,.h." ,			2 , 0xcb , 0x8c , 0x00 ,
					"res.1.,.l." ,			2 , 0xcb , 0x8d , 0x00 ,
					"res.2.,.(.hl.)." ,		2 , 0xcb , 0x96 , 0x00 ,
					"res.2.,.(.ix.+.*.)." ,	3 , 0xdd , 0xcb , 0x96 ,
					"res.2.,.(.iy.+.*.)." ,	3 , 0xfd , 0xcb , 0x96 ,
					"res.2.,.a." ,			2 , 0xcb , 0x97 , 0x00 ,
					"res.2.,.b." ,			2 , 0xcb , 0x90 , 0x00 ,
					"res.2.,.c." ,			2 , 0xcb , 0x91 , 0x00 ,
					"res.2.,.d." ,			2 , 0xcb , 0x92 , 0x00 ,
					"res.2.,.e." ,			2 , 0xcb , 0x93 , 0x00 ,
					"res.2.,.h." ,			2 , 0xcb , 0x94 , 0x00 ,
					"res.2.,.l." ,			2 , 0xcb , 0x95 , 0x00 ,
					"res.3.,.(.hl.)." ,		2 , 0xcb , 0x9e , 0x00 ,
					"res.3.,.(.ix.+.*.)." ,	3 , 0xdd , 0xcb , 0x9e ,
					"res.3.,.(.iy.+.*.)." ,	3 , 0xfd , 0xcb , 0x9e ,
					"res.3.,.a." ,			2 , 0xcb , 0x9f , 0x00 ,
					"res.3.,.b." ,			2 , 0xcb , 0x98 , 0x00 ,
					"res.3.,.c." ,			2 , 0xcb , 0x99 , 0x00 ,
					"res.3.,.d." ,			2 , 0xcb , 0x9a , 0x00 ,
					"res.3.,.e." ,			2 , 0xcb , 0x9b , 0x00 ,
					"res.3.,.h." ,			2 , 0xcb , 0x9c , 0x00 ,
					"res.3.,.l." ,			2 , 0xcb , 0x9d , 0x00 ,
					"res.4.,.(.hl.)." ,		2 , 0xcb , 0xa6 , 0x00 ,
					"res.4.,.(.ix.+.*.)." ,	3 , 0xdd , 0xcb , 0xa6 ,
					"res.4.,.(.iy.+.*.)." ,	3 , 0xfd , 0xcb , 0xa6 ,
					"res.4.,.a." ,			2 , 0xcb , 0xa7 , 0x00 ,
					"res.4.,.b." ,			2 , 0xcb , 0xa0 , 0x00 ,
					"res.4.,.c." ,			2 , 0xcb , 0xa1 , 0x00 ,
					"res.4.,.d." ,			2 , 0xcb , 0xa2 , 0x00 ,
					"res.4.,.e." ,			2 , 0xcb , 0xa3 , 0x00 ,
					"res.4.,.h." ,			2 , 0xcb , 0xa4 , 0x00 ,
					"res.4.,.l." ,			2 , 0xcb , 0xa5 , 0x00 ,
					"res.5.,.(.hl.)." ,		2 , 0xcb , 0xae , 0x00 ,
					"res.5.,.(.ix.+.*.)." ,	3 , 0xdd , 0xcb , 0xae ,
					"res.5.,.(.iy.+.*.)." ,	3 , 0xfd , 0xcb , 0xae ,
					"res.5.,.a." ,			2 , 0xcb , 0xaf , 0x00 ,
					"res.5.,.b." ,			2 , 0xcb , 0xa8 , 0x00 ,
					"res.5.,.c." ,			2 , 0xcb , 0xa9 , 0x00 ,
					"res.5.,.d." ,			2 , 0xcb , 0xaa , 0x00 ,
					"res.5.,.e." ,			2 , 0xcb , 0xab , 0x00 ,
					"res.5.,.h." ,			2 , 0xcb , 0xac , 0x00 ,
					"res.5.,.l." ,			2 , 0xcb , 0xad , 0x00 ,
					"res.6.,.(.hl.)." ,		2 , 0xcb , 0xb6 , 0x00 ,
					"res.6.,.(.ix.+.*.)." ,	3 , 0xdd , 0xcb , 0xb6 ,
					"res.6.,.(.iy.+.*.)." ,	3 , 0xfd , 0xcb , 0xb6 ,
					"res.6.,.a." ,			2 , 0xcb , 0xb7 , 0x00 ,
					"res.6.,.b." ,			2 , 0xcb , 0xb0 , 0x00 ,
					"res.6.,.c." ,			2 , 0xcb , 0xb1 , 0x00 ,
					"res.6.,.d." ,			2 , 0xcb , 0xb2 , 0x00 ,
					"res.6.,.e." ,			2 , 0xcb , 0xb3 , 0x00 ,
					"res.6.,.h." ,			2 , 0xcb , 0xb4 , 0x00 ,
					"res.6.,.l." ,			2 , 0xcb , 0xb5 , 0x00 ,
					"res.7.,.(.hl.)." ,		2 , 0xcb , 0xbe , 0x00 ,
					"res.7.,.(.ix.+.*.)." ,	3 , 0xdd , 0xcb , 0xbe ,
					"res.7.,.(.iy.+.*.)." ,	3 , 0xfd , 0xcb , 0xbe ,
					"res.7.,.a." ,			2 , 0xcb , 0xbf , 0x00 ,
					"res.7.,.b." ,			2 , 0xcb , 0xb8 , 0x00 ,
					"res.7.,.c." ,			2 , 0xcb , 0xb9 , 0x00 ,
					"res.7.,.d." ,			2 , 0xcb , 0xba , 0x00 ,
					"res.7.,.e." ,			2 , 0xcb , 0xbb , 0x00 ,
					"res.7.,.h." ,			2 , 0xcb , 0xbc , 0x00 ,
					"res.7.,.l." ,			2 , 0xcb , 0xbd , 0x00 ,
					"ret." ,				1 , 0xc9 , 0x00 , 0x00 ,
					"ret.c." , 				1 , 0xd8 , 0x00 , 0x00 ,
					"ret.m." , 				1 , 0xf8 , 0x00 , 0x00 ,
					"ret.nc." , 			1 , 0xd0 , 0x00 , 0x00 ,
					"ret.nz." , 			1 , 0xc0 , 0x00 , 0x00 ,
					"ret.p." , 				1 , 0xf0 , 0x00 , 0x00 ,
					"ret.pe." , 			1 , 0xe8 , 0x00 , 0x00 ,
					"ret.po." , 			1 , 0xe0 , 0x00 , 0x00 ,
					"ret.z." , 				1 , 0xc8 , 0x00 , 0x00 ,
					"reti." , 				2 , 0xed , 0x4d , 0x00 ,
					"retn." , 				2 , 0xed , 0x45 , 0x00 ,
					"rl.(.hl.)." ,			2 , 0xcb , 0x16 , 0x00 ,
					"rl.(.ix.+.*.)." ,		3 , 0xdd , 0xcb , 0x16 ,
					"rl.(.iy.+.*.)." ,		3 , 0xfd , 0xcb , 0x16 ,
					"rl.a." ,				2 , 0xcb , 0x17 , 0x00 ,
					"rl.b." ,				2 , 0xcb , 0x10 , 0x00 ,
					"rl.c." ,				2 , 0xcb , 0x11 , 0x00 ,
					"rld." ,				2 , 0xed , 0x6f , 0x00 ,
					"rl.d." ,				2 , 0xcb , 0x12 , 0x00 ,
					"rl.e." ,				2 , 0xcb , 0x13 , 0x00 ,
					"rl.h." ,				2 , 0xcb , 0x14 , 0x00 ,
					"rl.l." ,				2 , 0xcb , 0x15 , 0x00 ,
					"rla." ,				1 , 0x17 , 0x00 , 0x00 ,
					"rlc.(.hl.).",			2 , 0xcb , 0x06 , 0x00 ,
					"rlc.(.ix.+.*.)." ,		3 , 0xdd , 0xcb , 0x06 ,
					"rlc.(.iy.+.*.)." ,		3 , 0xfd , 0xcb , 0x06 ,
					"rlca." ,				1 , 0x07 , 0x00 , 0x00 ,
					"rlc.a." ,				2 , 0xcb , 0x07 , 0x00 ,
					"rlc.b." ,				2 , 0xcb , 0x00 , 0x00 ,
					"rlc.c." ,				2 , 0xcb , 0x01 , 0x00 ,
					"rlc.d." ,				2 , 0xcb , 0x02 , 0x00 ,
					"rlc.e." ,				2 , 0xcb , 0x03 , 0x00 ,
					"rlc.h." ,				2 , 0xcb , 0x04 , 0x00 ,
					"rlc.l." ,				2 , 0xcb , 0x05 , 0x00 ,
					"rr.(.hl.)." ,			2 , 0xcb , 0x1e , 0x00 ,
					"rr.(.ix.+.*.)." ,		3 , 0xdd , 0xcb , 0x1e ,
					"rr.(.iy.+.*.)." ,		3 , 0xfd , 0xcb , 0x1e ,
					"rra." ,				1 , 0x1f , 0x00 , 0x00 ,
					"rr.a." ,				2 , 0xcb , 0x1f , 0x00 ,
					"rr.b." ,				2 , 0xcb , 0x18 , 0x00 ,
					"rr.c." ,				2 , 0xcb , 0x19 , 0x00 ,
					"rrd." ,				2 , 0xed , 0x67 , 0x00 ,
					"rr.d." ,				2 , 0xcb , 0x1a , 0x00 ,
					"rr.e." ,				2 , 0xcb , 0x1b , 0x00 ,
					"rr.h." ,				2 , 0xcb , 0x1c , 0x00 ,
					"rr.l." ,				2 , 0xcb , 0x1d , 0x00 ,
					"rrc.(.hl.).",			2 , 0xcb , 0x0e , 0x00 ,
					"rrc.(.ix.+.*.)." ,		3 , 0xdd , 0xcb , 0x0e ,
					"rrc.(.iy.+.*.)." ,		3 , 0xfd , 0xcb , 0x0e ,
					"rrca." ,				1 , 0x0f , 0x00 , 0x00 ,
					"rrc.a." ,				2 , 0xcb , 0x0f , 0x00 ,
					"rrc.b." ,				2 , 0xcb , 0x08 , 0x00 ,
					"rrc.c." ,				2 , 0xcb , 0x09 , 0x00 ,
					"rrc.d." ,				2 , 0xcb , 0x0a , 0x00 ,
					"rrc.e." ,				2 , 0xcb , 0x0b , 0x00 ,
					"rrc.h." ,				2 , 0xcb , 0x0c , 0x00 ,
					"rrc.l." ,				2 , 0xcb , 0x0d , 0x00 ,
					"rst.0h." ,				1 , 0xc7 , 0x00 , 0x00 ,
					"rst.10h." ,			1 , 0xd7 , 0x00 , 0x00 ,
					"rst.18h." ,			1 , 0xdf , 0x00 , 0x00 ,
					"rst.20h." ,			1 , 0xe7 , 0x00 , 0x00 ,
					"rst.28h." ,			1 , 0xef , 0x00 , 0x00 ,
					"rst.30h." ,			1 , 0xf7 , 0x00 , 0x00 ,
					"rst.38h." ,			1 , 0xff , 0x00 , 0x00 ,
					"rst.8h." ,				1 , 0xcf , 0x00 , 0x00 ,
					"rst.0." ,				1 , 0xc7 , 0x00 , 0x00 ,
					"rst.16." ,			1 , 0xd7 , 0x00 , 0x00 ,
					"rst.24." ,			1 , 0xdf , 0x00 , 0x00 ,
					"rst.32." ,			1 , 0xe7 , 0x00 , 0x00 ,
					"rst.40." ,			1 , 0xef , 0x00 , 0x00 ,
					"rst.48." ,			1 , 0xf7 , 0x00 , 0x00 ,
					"rst.56." ,			1 , 0xff , 0x00 , 0x00 ,
					"rst.8." ,				1 , 0xcf , 0x00 , 0x00 ,
					"sbc.a.,.(.hl.)." ,		1 , 0x9e , 0x00 , 0x00 ,
					"sbc.a.,.(.ix.+.*.)." ,	2 , 0xdd , 0x9e , 0x00 ,
					"sbc.a.,.(.iy.+.*.)." ,	2 , 0xfd , 0x9e , 0x00 ,
					"sbc.a.,.a." ,			1 , 0x9f , 0x00 , 0x00 ,
					"sbc.a.,.b." ,			1 , 0x98 , 0x00 , 0x00 ,
					"sbc.a.,.c." ,			1 , 0x99 , 0x00 , 0x00 ,
					"sbc.a.,.d." ,			1 , 0x9a , 0x00 , 0x00 ,
					"sbc.a.,.e." ,			1 , 0x9b , 0x00 , 0x00 ,
					"sbc.a.,.h." ,			1 , 0x9c , 0x00 , 0x00 ,
					"sbc.a.,.l." ,			1 , 0x9d , 0x00 , 0x00 ,
					"sbc.a.,.*." ,			1 , 0xde , 0x00 , 0x00 ,
					"sbc.hl.,.bc." ,		2 , 0xed , 0x42 , 0x00 ,
					"sbc.hl.,.de." ,		2 , 0xed , 0x52 , 0x00 ,
					"sbc.hl.,.hl." ,		2 , 0xed , 0x62 , 0x00 ,
					"sbc.hl.,.sp." ,		2 , 0xed , 0x72 , 0x00 ,
					"scf." ,				1 , 0x37 , 0x00 , 0x00 ,
					"set.0.,.(.hl.)." ,		2 , 0xcb , 0xc6 , 0x00 ,
					"set.0.,.(.ix.+.*.)." ,	3 , 0xdd , 0xcb , 0xc6 ,
					"set.0.,.(.iy.+.*.)." ,	3 , 0xfd , 0xcb , 0xc6 ,
					"set.0.,.a." ,			2 , 0xcb , 0xc7 , 0x00 ,
					"set.0.,.b." ,			2 , 0xcb , 0xc0 , 0x00 ,
					"set.0.,.c." ,			2 , 0xcb , 0xc1 , 0x00 ,
					"set.0.,.d." ,			2 , 0xcb , 0xc2 , 0x00 ,
					"set.0.,.e." ,			2 , 0xcb , 0xc3 , 0x00 ,
					"set.0.,.h." ,			2 , 0xcb , 0xc4 , 0x00 ,
					"set.0.,.l." ,			2 , 0xcb , 0xc5 , 0x00 ,
					"set.1.,.(.hl.)." ,		2 , 0xcb , 0xce , 0x00 ,
					"set.1.,.(.ix.+.*.)." ,	3 , 0xdd , 0xcb , 0xce ,
					"set.1.,.(.iy.+.*.)." ,	3 , 0xfd , 0xcb , 0xce ,
					"set.1.,.a." ,			2 , 0xcb , 0xcf , 0x00 ,
					"set.1.,.b." ,			2 , 0xcb , 0xc8 , 0x00 ,
					"set.1.,.c." ,			2 , 0xcb , 0xc9 , 0x00 ,
					"set.1.,.d." ,			2 , 0xcb , 0xca , 0x00 ,
					"set.1.,.e." ,			2 , 0xcb , 0xcb , 0x00 ,
					"set.1.,.h." ,			2 , 0xcb , 0xcc , 0x00 ,
					"set.1.,.l." ,			2 , 0xcb , 0xcd , 0x00 ,
					"set.2.,.(.hl.)." ,		2 , 0xcb , 0xd6 , 0x00 ,
					"set.2.,.(.ix.+.*.)." ,	3 , 0xdd , 0xcb , 0xd6 ,
					"set.2.,.(.iy.+.*.)." ,	3 , 0xfd , 0xcb , 0xd6 ,
					"set.2.,.a." ,			2 , 0xcb , 0xd7 , 0x00 ,
					"set.2.,.b." ,			2 , 0xcb , 0xd0 , 0x00 ,
					"set.2.,.c." ,			2 , 0xcb , 0xd1 , 0x00 ,
					"set.2.,.d." ,			2 , 0xcb , 0xd2 , 0x00 ,
					"set.2.,.e." ,			2 , 0xcb , 0xd3 , 0x00 ,
					"set.2.,.h." ,			2 , 0xcb , 0xd4 , 0x00 ,
					"set.2.,.l." ,			2 , 0xcb , 0xd5 , 0x00 ,
					"set.3.,.(.hl.)." ,		2 , 0xcb , 0xde , 0x00 ,
					"set.3.,.(.ix.+.*.)." ,	3 , 0xdd , 0xcb , 0xde ,
					"set.3.,.(.iy.+.*.)." ,	3 , 0xfd , 0xcb , 0xde ,
					"set.3.,.a." ,			2 , 0xcb , 0xdf , 0x00 ,
					"set.3.,.b." ,			2 , 0xcb , 0xd8 , 0x00 ,
					"set.3.,.c." ,			2 , 0xcb , 0xd9 , 0x00 ,
					"set.3.,.d." ,			2 , 0xcb , 0xda , 0x00 ,
					"set.3.,.e." ,			2 , 0xcb , 0xdb , 0x00 ,
					"set.3.,.h." ,			2 , 0xcb , 0xdc , 0x00 ,
					"set.3.,.l." ,			2 , 0xcb , 0xdd , 0x00 ,
					"set.4.,.(.hl.)." ,		2 , 0xcb , 0xe6 , 0x00 ,
					"set.4.,.(.ix.+.*.)." ,	3 , 0xdd , 0xcb , 0xe6 ,
					"set.4.,.(.iy.+.*.)." ,	3 , 0xfd , 0xcb , 0xe6 ,
					"set.4.,.a." ,			2 , 0xcb , 0xe7 , 0x00 ,
					"set.4.,.b." ,			2 , 0xcb , 0xe0 , 0x00 ,
					"set.4.,.c." ,			2 , 0xcb , 0xe1 , 0x00 ,
					"set.4.,.d." ,			2 , 0xcb , 0xe2 , 0x00 ,
					"set.4.,.e." ,			2 , 0xcb , 0xe3 , 0x00 ,
					"set.4.,.h." ,			2 , 0xcb , 0xe4 , 0x00 ,
					"set.4.,.l." ,			2 , 0xcb , 0xe5 , 0x00 ,
					"set.5.,.(.hl.)." ,		2 , 0xcb , 0xee , 0x00 ,
					"set.5.,.(.ix.+.*.)." ,	3 , 0xdd , 0xcb , 0xee ,
					"set.5.,.(.iy.+.*.)." ,	3 , 0xfd , 0xcb , 0xee ,
					"set.5.,.a." ,			2 , 0xcb , 0xef , 0x00 ,
					"set.5.,.b." ,			2 , 0xcb , 0xe8 , 0x00 ,
					"set.5.,.c." ,			2 , 0xcb , 0xe9 , 0x00 ,
					"set.5.,.d." ,			2 , 0xcb , 0xea , 0x00 ,
					"set.5.,.e." ,			2 , 0xcb , 0xeb , 0x00 ,
					"set.5.,.h." ,			2 , 0xcb , 0xec , 0x00 ,
					"set.5.,.l." ,			2 , 0xcb , 0xed , 0x00 ,
					"set.6.,.(.hl.)." ,		2 , 0xcb , 0xf6 , 0x00 ,
					"set.6.,.(.ix.+.*.)." ,	3 , 0xdd , 0xcb , 0xf6 ,
					"set.6.,.(.iy.+.*.)." ,	3 , 0xfd , 0xcb , 0xf6 ,
					"set.6.,.a." ,			2 , 0xcb , 0xf7 , 0x00 ,
					"set.6.,.b." ,			2 , 0xcb , 0xf0 , 0x00 ,
					"set.6.,.c." ,			2 , 0xcb , 0xf1 , 0x00 ,
					"set.6.,.d." ,			2 , 0xcb , 0xf2 , 0x00 ,
					"set.6.,.e." ,			2 , 0xcb , 0xf3 , 0x00 ,
					"set.6.,.h." ,			2 , 0xcb , 0xf4 , 0x00 ,
					"set.6.,.l." ,			2 , 0xcb , 0xf5 , 0x00 ,
					"set.7.,.(.hl.)." ,		2 , 0xcb , 0xfe , 0x00 ,
					"set.7.,.(.ix.+.*.)." ,	3 , 0xdd , 0xcb , 0xfe ,
					"set.7.,.(.iy.+.*.)." ,	3 , 0xfd , 0xcb , 0xfe ,
					"set.7.,.a." ,			2 , 0xcb , 0xff , 0x00 ,
					"set.7.,.b." ,			2 , 0xcb , 0xf8 , 0x00 ,
					"set.7.,.c." ,			2 , 0xcb , 0xf9 , 0x00 ,
					"set.7.,.d." ,			2 , 0xcb , 0xfa , 0x00 ,
					"set.7.,.e." ,			2 , 0xcb , 0xfb , 0x00 ,
					"set.7.,.h." ,			2 , 0xcb , 0xfc , 0x00 ,
					"set.7.,.l." ,			2 , 0xcb , 0xfd , 0x00 ,
					"sla.(.hl.).",			2 , 0xcb , 0x26 , 0x00 ,
					"sla.(.ix.+.*.)." ,		3 , 0xdd , 0xcb , 0x26 ,
					"sla.(.iy.+.*.)." ,		3 , 0xfd , 0xcb , 0x26 ,
					"sla.a." ,				2 , 0xcb , 0x27 , 0x00 ,
					"sla.b." ,				2 , 0xcb , 0x20 , 0x00 ,
					"sla.c." ,				2 , 0xcb , 0x21 , 0x00 ,
					"sla.d." ,				2 , 0xcb , 0x22 , 0x00 ,
					"sla.e." ,				2 , 0xcb , 0x23 , 0x00 ,
					"sla.h." ,				2 , 0xcb , 0x24 , 0x00 ,
					"sla.l." ,				2 , 0xcb , 0x25 , 0x00 ,
					"sra.(.hl.)." ,			2 , 0xcb , 0x2e , 0x00 ,
					"sra.(.ix.+.*.)." ,		3 , 0xdd , 0xcb , 0x2e ,
					"sra.(.iy.+.*.)." ,		3 , 0xfd , 0xcb , 0x2e ,
					"sra.a." ,				2 , 0xcb , 0x2f , 0x00 ,
					"sra.b." ,				2 , 0xcb , 0x28 , 0x00 ,
					"sra.c." ,				2 , 0xcb , 0x29 , 0x00 ,
					"sra.d." ,				2 , 0xcb , 0x2a , 0x00 ,
					"sra.e." ,				2 , 0xcb , 0x2b , 0x00 ,
					"sra.h." ,				2 , 0xcb , 0x2c , 0x00 ,
					"sra.l." ,				2 , 0xcb , 0x2d , 0x00 ,
					"srl.(.hl.)." ,			2 , 0xcb , 0x3e , 0x00 ,
					"srl.(.ix.+.*.)." ,		3 , 0xdd , 0xcb , 0x3e ,
					"srl.(.iy.+.*.)." ,		3 , 0xfd , 0xcb , 0x3e ,
					"srl.a." ,				2 , 0xcb , 0x3f , 0x00 ,
					"srl.b." ,				2 , 0xcb , 0x38 , 0x00 ,
					"srl.c." ,				2 , 0xcb , 0x39 , 0x00 ,
					"srl.d." ,				2 , 0xcb , 0x3a , 0x00 ,
					"srl.e." ,				2 , 0xcb , 0x3b , 0x00 ,
					"srl.h." ,				2 , 0xcb , 0x3c , 0x00 ,
					"srl.l." ,				2 , 0xcb , 0x3d , 0x00 ,
					"sub.(.hl.)." ,			1 , 0x96 , 0x00 , 0x00 ,
					"sub.(.ix.+.*.)." ,		2 , 0xdd , 0x96 , 0x00 ,
					"sub.(.iy.+.*.)." ,		2 , 0xfd , 0x96 , 0x00 ,
					"sub.a." ,				1 , 0x97 , 0x00 , 0x00 ,
					"sub.b." ,				1 , 0x90 , 0x00 , 0x00 ,
					"sub.c." ,				1 , 0x91 , 0x00 , 0x00 ,
					"sub.d." ,				1 , 0x92 , 0x00 , 0x00 ,
					"sub.e." ,				1 , 0x93 , 0x00 , 0x00 ,
					"sub.h." ,				1 , 0x94 , 0x00 , 0x00 ,
					"sub.l." ,				1 , 0x95 , 0x00 , 0x00 ,
					"sub.*." ,				1 , 0xd6 , 0x00 , 0x00 ,
					"xor.(.hl.)." ,			1 , 0xae , 0x00 , 0x00 ,
					"xor.(.ix.+.*.)." ,		2 , 0xdd , 0xae , 0x00 ,
					"xor.(.iy.+.*.)." ,		2 , 0xfd , 0xae , 0x00 ,
					"xor.a." ,				1 , 0xaf , 0x00 , 0x00 ,
					"xor.b." ,				1 , 0xa8 , 0x00 , 0x00 ,
					"xor.c." ,				1 , 0xa9 , 0x00 , 0x00 ,
					"xor.d." ,				1 , 0xaa , 0x00 , 0x00 ,
					"xor.e." ,				1 , 0xab , 0x00 , 0x00 ,
					"xor.h." ,				1 , 0xac , 0x00 , 0x00 ,
					"xor.l." ,				1 , 0xad , 0x00 , 0x00 ,
					"xor.*." ,				1 , 0xee , 0x00 , 0x00 ,
					"*" ,					0 , 0x00 , 0x00 , 0x00
                 } ;     
                      
