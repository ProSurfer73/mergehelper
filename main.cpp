#include <iostream>

#include <windows.h>

#define APPTITLE "Hello World"

ATOM Init_App_Window_class(HINSTANCE);                 //Function to create and fill the Window class structure WNDCLASSEX
BOOL InitInstance(HINSTANCE,int);                      //Create window according to specifics in window class structure
LRESULT CALLBACK WinProc(HWND,UINT,WPARAM,LPARAM);     //Used to process the Messages from Windows to Application

//-------------------------- Main Program------------------------------------------------------------------------------------------------------//
int WINAPI WinMain(HINSTANCE hInstance,               //instance of the running program
	               HINSTANCE hPrevInstance,           //Previous Instance of the running Program
				   LPSTR     lpCmdLine,               //Long Pointer to Command line Arguments
				   int       nCmdShow)                //Showing the Window
	                                    {
											MSG m;                                //MSG is a typdef for a structure to get messages from windows OS

											Init_App_Window_class(hInstance);     //Create and fill the Window class structure WNDCLASSEX

											if(!InitInstance(hInstance,nCmdShow)) //Create window according to specifics in window class structure
												return FALSE;


											while(GetMessage(&m,NULL,0,0))        //Get message from Application Message Queue,Quit loop on Recieving WM_QUIT
												 {
												    TranslateMessage(&m);         //Transalate Message
													DispatchMessage(&m);          //Dispatch Message to WinProc() function
												 }
											return m.wParam;
	                                    }

ATOM Init_App_Window_class(HINSTANCE hInstance)  //Function to create and fill the Window class structure WNDCLASSEX
	                      {
								WNDCLASSEX wc;   //define wc as a structure of type WNDCLASSEX
								                 // Fill up the structure


								wc.cbSize        =  sizeof(WNDCLASSEX);                   //Size of the structure
								wc.style         =  CS_HREDRAW | CS_VREDRAW;              //Redraw if Size Changes
								wc.lpfnWndProc   =  (WNDPROC)WinProc;                     //Points to the Window Procedure" LRESULT CALLBACK WinProc (,,,,);"
								wc.cbClsExtra    =  0;                                    //No Extra Class Memory
								wc.cbWndExtra    =  0;                                    //No Extra Window Memory
								wc.hInstance     =  hInstance;                            //Handle to the instance
								wc.hIcon         =  NULL;                                 //No Icon
								wc.hCursor       =  LoadCursor(NULL,IDC_ARROW);           //Predefined Arrow
								wc.hbrBackground =  (HBRUSH) GetStockObject(WHITE_BRUSH); //Back ground Color
								wc.lpszMenuName  =  NULL;                                 //No Menu
								wc.lpszClassName =  APPTITLE;                             //Name of Window Class
								wc.hIconSm       =  NULL;

								return RegisterClassEx(&wc); //Register the Window class with OS
	                      }

BOOL InitInstance(HINSTANCE hInstance,int nCmdShow) //Create window according to specifics in window class structure
	             {
						HWND hWnd;					// Handle for the window

						hWnd = CreateWindow( APPTITLE,            // Window Class Name
							                 APPTITLE,            // Title Bar
											 WS_OVERLAPPEDWINDOW, // Window style
											 CW_USEDEFAULT,       // x position of Window
											 CW_USEDEFAULT,       // y position of Window
											 500,                 // Width of the Window
											 400,                 // Height of the Window
											 NULL,                // Parent Window
											 NULL,                // Menu
											 hInstance,           // Application Instance
											 NULL );              // Window parameters

						if(!hWnd)          //Was there an error in creating a window ? ie hWnd = 0;
							return FALSE;

						ShowWindow(hWnd,nCmdShow);  //show the Window
						UpdateWindow(hWnd);         //update the window inresponse to events
						return TRUE;
	             }

//---------Windows Call Back function to Process Messages from Windows-------------------------------------------------------------------------//

LRESULT CALLBACK WinProc (HWND hWnd,           //Window handle
	                      UINT message,        //messages from Windows like WM_DESTROY,WM_PAINT
						  WPARAM wParam,       //
						  LPARAM lParam)
                    	                   {
												switch(message)
							                          {

											             case WM_DESTROY: PostQuitMessage(0);
									                          break;

							                         }
												 return DefWindowProc(hWnd,message,wParam,lParam);
						                   }
