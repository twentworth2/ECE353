// 
//  Font data for Microsoft Sans Serif 8pt
// 

// Character bitmaps for Microsoft Sans Serif 8pt
const uint_8 microsoftSansSerif_8ptBitmaps[] = 
{
	// @0 'a' (5 pixels wide)
	0x00, //      
	0x00, //      
	0x00, //      
	0x70, //  ### 
	0x08, //     #
	0x78, //  ####
	0x88, // #   #
	0x88, // #   #
	0x78, //  ####

	// @9 'e' (5 pixels wide)
	0x00, //      
	0x00, //      
	0x00, //      
	0x70, //  ### 
	0x88, // #   #
	0xF8, // #####
	0x80, // #    
	0x88, // #   #
	0x70, //  ### 

	// @18 'i' (1 pixels wide)
	0x80, // #
	0x00, //  
	0x00, //  
	0x80, // #
	0x80, // #
	0x80, // #
	0x80, // #
	0x80, // #
	0x80, // #

	// @27 'm' (7 pixels wide)
	0x00, //        
	0x00, //        
	0x00, //        
	0xEC, // ### ## 
	0x92, // #  #  #
	0x92, // #  #  #
	0x92, // #  #  #
	0x92, // #  #  #
	0x92, // #  #  #

	// @36 'n' (5 pixels wide)
	0x00, //      
	0x00, //      
	0x00, //      
	0xB0, // # ## 
	0xC8, // ##  #
	0x88, // #   #
	0x88, // #   #
	0x88, // #   #
	0x88, // #   #

	// @45 'u' (5 pixels wide)
	0x00, //      
	0x00, //      
	0x00, //      
	0x88, // #   #
	0x88, // #   #
	0x88, // #   #
	0x88, // #   #
	0x98, // #  ##
	0x68, //  ## #
};

// Character descriptors for Microsoft Sans Serif 8pt
// { [Char width in bits], [Offset into microsoftSansSerif_8ptCharBitmaps in bytes] }
const FONT_CHAR_INFO microsoftSansSerif_8ptDescriptors[] = 
{
	{5, 0}, 		// a 
	{0, 0}, 		// b 
	{0, 0}, 		// c 
	{0, 0}, 		// d 
	{5, 9}, 		// e 
	{0, 0}, 		// f 
	{0, 0}, 		// g 
	{0, 0}, 		// h 
	{1, 18}, 		// i 
	{0, 0}, 		// j 
	{0, 0}, 		// k 
	{0, 0}, 		// l 
	{7, 27}, 		// m 
	{5, 36}, 		// n 
	{0, 0}, 		// o 
	{0, 0}, 		// p 
	{0, 0}, 		// q 
	{0, 0}, 		// r 
	{0, 0}, 		// s 
	{0, 0}, 		// t 
	{5, 45}, 		// u 
};

// Font information for Microsoft Sans Serif 8pt
const FONT_INFO microsoftSansSerif_8ptFontInfo =
{
	2, //  Character height
	'a', //  Start character
	'u', //  End character
	2, //  Width, in pixels, of space character
	microsoftSansSerif_8ptDescriptors, //  Character descriptor array
	microsoftSansSerif_8ptBitmaps, //  Character bitmap array
};

