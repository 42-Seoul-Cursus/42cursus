NAME
	   MiniLibX - Handle events

SYNOPSYS
	   int
	   mlx_loop ( void *mlx_ptr );

	   int
	   mlx_key_hook ( void *win_ptr, int (*funct_ptr)(), void *param );

	   int
	   mlx_mouse_hook ( void *win_ptr, int (*funct_ptr)(), void *param );

	   int
	   mlx_expose_hook ( void *win_ptr, int (*funct_ptr)(), void *param );

	   int
	   mlx_loop_hook ( void *mlx_ptr, int (*funct_ptr)(), void *param );


EVENTS
	   Both X-Window and MacOSX graphical systems are bi-directionnal.  On one hand, the program sends orders to the screen to display pixels, images, and so on. On the other hand, it can get information from the keyboard and mouse asso-
	   ciated to the screen. To do so, the program receives "events" from the keyboard or the mouse.


DESCRIPTION
	   To receive events, you must use mlx_loop (). This function never returns. It is an infinite loop that waits for an event, and then calls a user-defined function associated with this event.  A single parameter is needed,  the  con-
	   nection identifier mlx_ptr (see the mlx manual).

	   You can assign different functions to the three following events:
	   - A key is pressed
	   - The mouse button is pressed
	   - A part of the window should be re-drawn (this is called an "expose" event, and it is your program's job to handle it).

	   Each window can define a different function for the same event.

	   The three functions mlx_key_hook (), mlx_mouse_hook () and mlx_expose_hook () work exactly the same way.  funct_ptr is a pointer to the function you want to be called when an event occurs. This assignment is specific to the window
	   defined by the win_ptr identifier. The param adress will be passed to the function everytime it is called, and should be used to store the parameters it might need.

	   The syntax for the mlx_loop_hook () function is identical to the previous ones, but the given function will be called when no event occurs.

	   When it catches an event, the MiniLibX calls the corresponding function with fixed parameters:

		 expose_hook(void *param);
		 key_hook(int keycode,void *param);
		 mouse_hook(int button,int x,int y,void *param);
		 loop_hook(void *param);

	   These function names are arbitrary. They here are used to distinguish parameters according to the event. These functions are NOT part of the MiniLibX.

	   param is the address specified in the mlx_*_hook calls. This address is never used nor modified by the MiniLibX. On key and mouse events, additional information is passed: keycode tells you which key is pressed (X11 : look for the
	   include file "keysymdef.h", MacOS : create a small software and find out by yourself), ( x , y ) are the coordinates of the mouse click in the window, and button tells you which mouse button was pressed.


GOING FURTHER WITH EVENTS
	   The MiniLibX provides a much generic access to all type of events. The mlx.h include define mlx_hook() in the same manner mlx_*_hook functions work. The event and mask values will be taken from the X11 include file "X.h" (even for
	   MacOSX, for compatibility purposes)

	   See source code of mlx_int_param_event.c to find out how the MiniLibX will call your own function for a specific event.


SEE ALSO
	   mlx(3), mlx_new_window(3), mlx_pixel_put(3), mlx_new_image(3)


AUTHOR
	   Copyright ol@ - 2002-2015 - Olivier Crouzet

NAME
	   MiniLibX - 이벤트 처리

SYNOPSYS
	   int
	   MLX_LOOP ( void *MLX_PTR );

	   int
	   mlx_key_hook ( void *win_ptr, int (*funct_ptr)(), void *param );

	   int
	   MLX_MOUSE_HOOK ( void *win_ptr, int (*funct_ptr)(), void *param );

	   int
	   MLX_EXPOSE_HOOK ( void *win_ptr, int (*funct_ptr)(), void *param );

	   int
	   MLX_LOOP_HOOK ( void *MLX_PTR, int (*FUNCT_PTR)(), void *PARAM );


EVENTS
	   X-윈도우와 MacOSX 그래픽 시스템은 모두 양방향입니다.  한편으로 프로그램은 픽셀, 이미지 등을 표시하도록 화면에 명령을 보냅니다. 다른 한편으로는 키보드와 마우스로부터 정보를 가져올 수도 있습니다.
	   정보를 가져올 수 있습니다. 이를 위해 프로그램은 키보드 또는 마우스로부터 "이벤트"를 수신합니다.


설명
	   이벤트를 수신하려면 mlx_loop ()를 사용해야 합니다. 이 함수는 절대 반환되지 않습니다. 이 함수는 이벤트를 기다린 다음 이 이벤트와 관련된 사용자 정의 함수를 호출하는 무한 루프입니다.  하나의 매개변수가 필요합니다.
	   연결 식별자 MLX_PTR(MLX 매뉴얼 참조).

	   다음 세 가지 이벤트에 서로 다른 함수를 할당할 수 있습니다:
	   - 키가 눌림
	   - 마우스 버튼을 눌렀습니다.
	   - 창의 일부가 다시 그려져야 합니다(이를 "노출" 이벤트라고 하며, 이를 처리하는 것은 프로그램의 작업입니다).

	   각 창은 동일한 이벤트에 대해 서로 다른 함수를 정의할 수 있습니다.

	   세 가지 함수 mlx_key_hook (), mlx_mouse_hook () 및 mlx_expose_hook ()은 정확히 같은 방식으로 작동합니다. funct_ptr은 이벤트가 발생할 때 호출하려는 함수에 대한 포인터입니다. 이 할당은 win_ptr 식별자로 정의된 창
	   에 한정됩니다. 매개변수 주소는 함수가 호출될 때마다 함수에 전달되며, 필요한 매개변수를 저장하는 데 사용해야 합니다.

	   mlx_loop_hook () 함수의 구문은 이전 구문과 동일하지만 이벤트가 발생하지 않을 때 지정된 함수가 호출됩니다.

	   이벤트가 발생하면 MiniLibX는 고정된 파라미터를 사용하여 해당 함수를 호출합니다:

		 expose_hook(void *param);
		 key_hook(int keycode,void *param);
		 mouse_hook(int button,int x,int y,void *param);
		 LOOP_HOOK(void *param);

	   이러한 함수 이름은 임의적입니다. 여기서는 이벤트에 따라 매개변수를 구분하기 위해 사용됩니다. 이 함수는 MiniLibX의 일부가 아닙니다.

	   param은 mlx_*_hook 호출에 지정된 주소입니다. 이 주소는 MiniLibX에서 사용되거나 수정되지 않습니다. 키와 마우스 이벤트에서 추가 정보가 전달됩니다: 키코드는 어떤 키를 눌렀는지 알려줍니다(X11: 키코드가 있는
	   포함 파일 "keysymdef.h", MacOS : 작은 소프트웨어를 만들어 직접 찾아보세요), ( x , y )는 창에서 마우스 클릭의 좌표이며 버튼은 어떤 마우스 버튼을 눌렀는지 알려줍니다.


이벤트와 함께 더 나아가기
	   MiniLibX는 모든 유형의 이벤트에 대한 매우 일반적인 접근 방식을 제공합니다. mlx.h에는 mlx_*_hook 함수가 작동하는 방식과 동일한 방식으로 mlx_hook()을 정의하는 함수가 포함되어 있습니다. 이벤트 및 마스크 값은 X11 인클루드 파일 "X.h"에서 가져옵니다. (심지어
	   호환성을 위해 MacOSX의 경우에도)

	   특정 이벤트에 대해 MiniLibX가 자체 함수를 호출하는 방법을 알아보려면 mlx_int_param_event.c의 소스 코드를 참조하세요.


참조
	   MLX(3), MLX_NEW_WINDOW(3), MLX_PIXEL_PUT(3), MLX_NEW_IMAGE(3)


AUTHOR
	   저작권 ol@ - 2002-2015 - 올리비에 크루제
