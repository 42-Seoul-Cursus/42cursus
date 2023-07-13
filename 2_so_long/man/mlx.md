NAME
	   MiniLibX - Simple Graphical Interface Library for students

SYNOPSYS
	   #include <mlx.h>

	   void *
	   mlx_init ();


DESCRIPTION
	   MiniLibX  is  an  easy way to create graphical software, without any X-
	   Window/Cocoa programming knowledge. It provides simple window creation,
	   a drawing tool, image and basic events management.


BSD/LINUX X-WINDOW CONCEPT
	   X-Window  is a network-oriented graphical system for Unix.  It is based
	   on two main parts:
	   On one side, your software wants to draw something on the screen and/or
	   get keyboard & mouse entries.
	   On  the other side, the X-Server manages the screen, keyboard and mouse
	   (It is often refered to as a "display").
	   A network connection must be established between these two entities  to
	   send  drawing  orders  (from  the  software  to the X-Server), and key-
	   board/mouse events (from the X-Server to the software).


MACOSX CONCEPT
	   The MacOSX operating system handle graphical access to the  screen  (or
	   "display").
	   On one side, your software wants to draw something on the screen and/or
	   get keyboard & mouse entries.
	   On the other side, the underlying MacOSX graphical framework that  han-
	   dles the screen, the windowing system, keyboard and mouse.
	   A connection between these two entities must be established.


INCLUDE FILE
	   mlx.h  should  be  included  for a correct use of the MiniLibX API.  It
	   only contains function prototypes, no structure is needed.


LIBRARY FUNCTIONS
	   First of all, you need to initialize the connection between your  soft-
	   ware  and  the display.  Once this connection is established, you'll be
	   able to use other MiniLibX functions to send the graphical orders, like
	   "I  want  to draw a yellow pixel in this window" or "did the user hit a
	   key?".

	   The mlx_init function will create this connection.  No  parameters  are
	   needed,  ant it will return a void * identifier, used for further calls
	   to the library routines.

	   All other MiniLibX functions are described in the following man pages:


	   mlx_new_window      : manage windows

	   mlx_pixel_put       : draw inside window

	   mlx_new_image       : manipulate images

	   mlx_loop            : handle keyboard or mouse events


LINKING MiniLibX on BSD/Linux and X-Window
	   To use MiniLibX functions, you'll need to link your software with  sev-
	   eral  libraries,  including  the  MiniLibX library itself.  To do this,
	   simply add the following arguments at linking time:

	   -lmlx -lXext -lX11

	   You may also need to specify the path to these libraries, using the  -L
	   flag.


LINKING MiniLibX on MACOSX
	   To  use  MiniLibX functions, you'll need to link your software with the
	   MiniLibX library, and several system frameworks:

	   -lmlx -framework OpenGL -framework AppKit

	   You may also need to specify the path to the  MiniLibX  library,  using
	   the -L flag.


RETURN VALUES
	   If  mlx_init()  fails to set up the connection to the graphical system,
	   it will return NULL, otherwise a non-null pointer is returned as a con-
	   nection identifier.


SEE ALSO
	   mlx_new_window(3), mlx_pixel_put(3), mlx_new_image(3), mlx_loop(3)


AUTHOR
	   Copyright ol@ - 2002-2015 - Olivier Crouzet



	September 19, 2002                   MiniLibX(3)

NAME
	   MiniLibX - 학생들을 위한 간단한 그래픽 인터페이스 라이브러리

SYNOPSYS
	   #include <mlx.h>

	   void *
	   MLX_INIT ();


설명
	   MiniLibX는 그래픽 소프트웨어를 쉽게 만들 수 있는 방법입니다.
	   창/코코아 프로그래밍 지식 없이도 그래픽 소프트웨어를 쉽게 만들 수 있습니다. 간단한 창 생성을 제공합니다,
	   그리기 도구, 이미지 및 기본 이벤트 관리 기능을 제공합니다.



	   X-윈도우는 유닉스용 네트워크 지향 그래픽 시스템입니다.  이 시스템은 다음을 기반으로 합니다.
	   두 가지 주요 부분을 기반으로 합니다:
	   한쪽에서는 소프트웨어가 화면에 무언가를 그리거나
	   키보드 및 마우스 입력을 받으려고 합니다.
	   다른 쪽에서는 X-서버가 화면, 키보드 및 마우스를 관리합니다.
	   ("디스플레이"라고도 함).
	   다음 작업을 수행하려면 이 두 엔티티 간에 네트워크 연결이 설정되어야 합니다.
	   드로잉 오더(소프트웨어에서 X-서버로) 및 키 전송
	   보드/마우스 이벤트(X-서버에서 소프트웨어로)를 전송하려면 이 두 개체 간에 네트워크 연결이 필요합니다.


MacOSX 개념
	   MacOSX 운영 체제는 화면에 대한 그래픽 액세스(또는
	   "디스플레이").
	   한 쪽에서는 소프트웨어가 화면에 무언가를 그리거나
	   키보드 및 마우스 입력을 받으려고 합니다.
	   다른 한편으로는 화면을 처리하는 기본 MacOSX 그래픽 프레임워크가 있습니다.
	   화면, 윈도우 시스템, 키보드 및 마우스를 처리합니다.
	   이 두 엔티티 간에 연결이 설정되어야 합니다.


파일 포함
	   MiniLibX API를 올바르게 사용하려면 mlx.h를 포함해야 합니다.  It
	   함수 프로토타입만 포함하며 구조는 필요하지 않습니다.


라이브러리 함수
	   우선, 소프트 웨어와 디스플레이 간의 연결을 초기화해야 합니다.
	   소프트 웨어와 디스플레이 사이의 연결을 초기화해야 합니다.  이 연결이 설정되면 다음을 수행할 수 있습니다.
	   다음과 같은 그래픽 명령을 전송하기 위해 다른 MiniLibX 함수를 사용할 수 있습니다.
	   "이 창에 노란색 픽셀을 그리고 싶습니다." 또는 "사용자가 키를 눌렀습니까?
	   키를 눌렀나요?".

	   mlx_init 함수는 이 연결을 생성합니다.  매개변수는
	   매개변수가 필요하지 않으며, 라이브러리 루틴에 대한 추가 호출에 사용되는 공백 * 식별자를 반환합니다.
	   를 반환합니다.

	   다른 모든 MiniLibX 함수는 다음 매뉴얼 페이지에 설명되어 있습니다:


	   MLX_NEW_WINDOW: 창 관리

	   mlx_pixel_put : 창 안에 그리기

	   mlx_new_image : 이미지 조작

	   mlx_loop : 키보드 또는 마우스 이벤트 처리


BSD/리눅스 및 X-윈도우에서 MiniLibX 연결하기
	   MiniLibX 함수를 사용하려면 소프트웨어를 다음과 같은 여러 라이브러리와 연결해야 합니다.
	   다른 라이브러리와 연결해야 합니다.  이렇게 하려면
	   링크할 때 다음 인수를 추가하기만 하면 됩니다:

	   -lmlx -lXext -lX11

	   또한 -L 플래그를 사용하여 이러한 라이브러리의 경로를 지정해야 할 수도 있습니다.
	   플래그를 사용하여 이들 라이브러리의 경로를 지정할 수도 있습니다.


MacOSX에서 MiniLibX 연결하기
	   MiniLibX 함수를 사용하려면 소프트웨어와
	   MiniLibX 라이브러리 및 여러 시스템 프레임워크와 연결해야 합니다:

	   -lmlx -프레임워크 OpenGL -프레임워크 AppKit

	   또한 -L 플래그를 사용하여 MiniLibX 라이브러리의 경로를 지정해야 할 수도 있습니다.
	   를 사용하여 경로를 지정해야 할 수도 있습니다.


반환 값
	   mlx_init()이 그래픽 시스템에 대한 연결을 설정하는 데 실패한 경우,
	   을 반환하고, 그렇지 않으면 널이 아닌 포인터가 연결 식별자로 반환됩니다.
	   연결 식별자로 반환됩니다.


참조
	   MLX_NEW_WINDOW(3), MLX_PIXEL_PUT(3), MLX_NEW_IMAGE(3), MLX_LOOP(3)


AUTHOR
	   저작권 ol@ - 2002-2015 - 올리비에 크루제



	September 19, 2002 MiniLibX(3)
