NAME
	   MiniLibX - Manipulating images

SYNOPSYS
	   void *
	   mlx_new_image ( void *mlx_ptr, int width, int height );

	   char *
	   mlx_get_data_addr ( void *img_ptr, int *bits_per_pixel, int *size_line, int *endian );

	   int
	   mlx_put_image_to_window ( void *mlx_ptr, void *win_ptr, void *img_ptr, int x, int y );

	   unsigned int
	   mlx_get_color_value ( void *mlx_ptr, int color );

	   void *
	   mlx_xpm_to_image ( void *mlx_ptr, char **xpm_data, int *width, int *height );

	   void *
	   mlx_xpm_file_to_image ( void *mlx_ptr, char *filename, int *width, int *height );

	   int
	   mlx_destroy_image ( void *mlx_ptr, void *img_ptr );



DESCRIPTION
	   mlx_new_image  ()  creates a new image in memory. It returns a void * identifier needed to manipulate this image later. It only needs the size of the image to be created, using the width and height parameters, and the mlx_ptr con-
	   nection identifier (see the mlx manual).

	   The user can draw inside the image (see below), and can dump the image inside a specified window at any time to display it on the screen. This is done using mlx_put_image_to_window (). Three identifiers are needed  here,  for  the
	   connection to the display, the window to use, and the image (respectively mlx_ptr , win_ptr and img_ptr ). The ( x , y ) coordinates define where the image should be placed in the window.

	   mlx_get_data_addr  ()  returns  information  about the created image, allowing a user to modify it later. The img_ptr parameter specifies the image to use. The three next parameters should be the addresses of three different valid
	   integers.  bits_per_pixel will be filled with the number of bits needed to represent a pixel color (also called the depth of the image).  size_line is the number of bytes used to store one line of the image in memory.  This infor-
	   mation is needed to move from one line to another in the image.  endian tells you wether the pixel color in the image needs to be stored in little endian ( endian == 0), or big endian ( endian == 1).

	   mlx_get_data_addr  returns a char * address that represents the begining of the memory area where the image is stored. From this adress, the first bits_per_pixel bits represent the color of the first pixel in the first line of the
	   image. The second group of bits_per_pixel bits represent the second pixel of the first line, and so on.  Add size_line to the adress to get the begining of the second line. You can reach any pixels of the image that way.

	   mlx_destroy_image destroys the given image ( img_ptr ).


STORING COLOR INSIDE IMAGES
	   Depending on the display, the number of bits used to store a pixel color can change. The user usually represents a color in RGB mode, using one byte for each component (see mlx_pixel_put manual). This must be translated to fit the
	   bits_per_pixel  requirement of the image, and make the color understandable to the graphical system.  That is the purpose of the mlx_get_color_value () function. It takes a standard RGB color parameter, and returns an unsigned int
	   value.  The bits_per_pixel least significant bits of this value can be stored in the image.

	   Keep in mind that the least significant bits position depends on the local computer's endian. If the endian of the image (in fact the endian of the X-Server's computer for remote X11 display) differs from the  local  endian,  then
	   the value should be transformed before being used.


XPM IMAGES
	   The  mlx_xpm_to_image  () and mlx_xpm_file_to_image () functions will create a new image the same way.  They will fill it using the specified xpm_data or filename , depending on which function is used.  Note that MiniLibX does not
	   use the standard Xpm library to deal with xpm images. You may not be able to read all types of xpm images. It however handles transparency.


RETURN VALUES
	   The three functions that create images, mlx_new_image() , mlx_xpm_to_image() and mlx_xpm_file_to_image() , will return NULL if an error occurs. Otherwise they return a non-null pointer as an image identifier.



SEE ALSO
	   mlx(3), mlx_new_window(3), mlx_pixel_put(3), mlx_loop(3)


AUTHOR
	   Copyright ol@ - 2002-2015 - Olivier Crouzet

NAME
	   MiniLibX - 이미지 조작

SYNOPSYS
	   void *
	   MLX_NEW_IMAGE ( void *MLX_PTR, int width, int height );

	   char *
	   mlx_get_data_addr ( void *img_ptr, int *bits_per_pixel, int *size_line, int *endian );

	   int
	   mlx_put_image_to_window ( void *mlx_ptr, void *win_ptr, void *img_ptr, int x, int y );

	   부호 없는 int
	   mlx_get_color_value ( void *mlx_ptr, int color );

	   void *
	   MLX_XPM_TO_IMAGE ( void *mlx_ptr, char **xpm_data, int *width, int *height );

	   void *
	   mlx_xpm_file_to_image ( void *mlx_ptr, char *filename, int *width, int *height );

	   int
	   MLX_DESTROY_IMAGE ( void *MLX_PTR, void *IMG_PTR );



설명
	   mlx_new_image ()는 메모리에 새 이미지를 생성합니다. 이 함수는 나중에 이 이미지를 조작하는 데 필요한 void * 식별자를 반환합니다. 이 함수는 너비와 높이 매개변수를 사용하여 생성할 이미지의 크기와 mlx_ptr 연결 식별자만 필요합니다.
	   연결 식별자만 있으면 됩니다(mlx 매뉴얼 참조).

	   사용자는 이미지 내부에 그림을 그릴 수 있으며(아래 참조), 언제든지 지정된 창 안에 이미지를 덤프하여 화면에 표시할 수 있습니다. 이 작업은 mlx_put_image_to_window ()를 사용하여 수행됩니다. 여기에는 세 가지 식별자가 필요합니다.
	   디스플레이에 대한 연결, 사용할 창, 이미지(각각 mlx_ptr , win_ptr 및 img_ptr)입니다. ( x , y ) 좌표는 창에서 이미지가 배치될 위치를 정의합니다.

	   mlx_get_data_addr ()은 생성된 이미지에 대한 정보를 반환하여 사용자가 나중에 수정할 수 있도록 합니다. img_ptr 매개변수는 사용할 이미지를 지정합니다. 다음 세 개의 매개 변수는 서로 다른 세 개의 유효한
	   정수여야 합니다. bits_per_pixel은 픽셀 색상(이미지의 깊이라고도 함)을 표현하는 데 필요한 비트 수로 채워집니다. size_line은 이미지 한 줄을 메모리에 저장하는 데 사용되는 바이트 수입니다.  이 정보는
	   는 이미지에서 한 줄에서 다른 줄로 이동하는 데 필요합니다. 엔디안은 이미지의 픽셀 색상을 작은 엔디안(엔디안 == 0)으로 저장할지 큰 엔디안(엔디안 == 1)으로 저장할지 여부를 알려줍니다.

	   mlx_get_data_addr은 이미지가 저장된 메모리 영역의 시작을 나타내는 문자 * 주소를 반환합니다. 이 주소에서 첫 번째 비트당 픽셀 비트는 이미지의 첫 번째 줄에 있는 첫 번째 픽셀의 색상을 나타냅니다.
	   이미지의 첫 번째 줄에 있는 첫 번째 픽셀의 색을 나타냅니다. 두 번째 bits_per_pixel 비트 그룹은 첫 번째 줄의 두 번째 픽셀을 나타내는 식으로 나타납니다.  주소에 size_line을 추가하여 두 번째 줄의 시작 부분을 가져옵니다. 이 방법으로 이미지의 모든 픽셀에 도달할 수 있습니다.

	   mlx_destroy_image는 주어진 이미지( img_ptr )를 파괴합니다.


이미지 내부에 색상 저장
	   디스플레이에 따라 픽셀 색상을 저장하는 데 사용되는 비트 수가 달라질 수 있습니다. 사용자는 일반적으로 RGB 모드에서 각 구성 요소에 대해 1바이트를 사용하여 색상을 표현합니다(mlx_pixel_put 매뉴얼 참조). 이는 반드시
	   픽셀당 비트 수에 맞게 변환해야 하며, 그래픽 시스템에서 색상을 이해할 수 있도록 해야 합니다.  이것이 mlx_get_color_value () 함수의 목적입니다. 이 함수는 표준 RGB 색상 매개변수를 받아 부호 없는 int
	   값을 반환합니다.  이 값의 픽셀당 최하위 비트는 이미지에 저장할 수 있습니다.

	   최하위 비트 위치는 로컬 컴퓨터의 엔디안에 따라 달라진다는 점에 유의하세요. 이미지의 엔디안(실제로는 원격 X11 디스플레이를 위한 X-Server 컴퓨터의 엔디안)이 로컬 엔디안과 다른 경우
	   값을 사용하기 전에 변환해야 합니다.


XPM 이미지
	   mlx_xpm_to_image () 및 mlx_xpm_file_to_image () 함수는 동일한 방식으로 새 이미지를 생성합니다.  사용되는 함수에 따라 지정된 xpm_data 또는 파일 이름 을 사용하여 이미지를 채웁니다.  MiniLibX는
	   표준 Xpm 라이브러리를 사용하여 xpm 이미지를 처리하지 않습니다. 모든 유형의 xpm 이미지를 읽지 못할 수도 있습니다. 그러나 투명도는 처리합니다.


반환 값
	   이미지를 생성하는 세 가지 함수인 mlx_new_image() , mlx_xpm_to_image() 및 mlx_xpm_file_to_image()는 오류가 발생하면 NULL을 반환합니다. 그렇지 않으면 이미지 식별자로 널이 아닌 포인터를 반환합니다.



참조
	   MLX(3), MLX_NEW_WINDOW(3), MLX_PIXEL_PUT(3), MLX_LOOP(3)


AUTHOR
	   저작권 ol@ - 2002-2015 - 올리비에 크루제
