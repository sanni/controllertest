#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdint.h>
#include <libdragon.h>
#include <stdlib.h>

int main(void)
{
    /* enable interrupts (on the CPU) */
    init_interrupts();

    /* Initialize Display */
	display_init( RESOLUTION_320x240, DEPTH_32_BPP, 2, GAMMA_NONE, ANTIALIAS_RESAMPLE );
   
	/* Initialize Filesystem for Sprites */
    dfs_init( DFS_DEFAULT_LOCATION );
    
    /* Initialize Controller */
    controller_init();
   
    /* Read in single sprite */
    int fp = dfs_open("/neo.sprite");
    sprite_t *neo = malloc( dfs_size( fp ) );
    dfs_read( neo, 1, dfs_size( fp ), fp );
    dfs_close( fp ); 
    
    fp = dfs_open("/leaf.sprite");
    sprite_t *leaf = malloc( dfs_size( fp ) );
    dfs_read( leaf, 1, dfs_size( fp ), fp );
    dfs_close( fp ); 
    
    fp = dfs_open("/u.sprite");
    sprite_t *u = malloc( dfs_size( fp ) );
    dfs_read( u, 1, dfs_size( fp ), fp );
    dfs_close( fp ); 
    
    fp = dfs_open("/d.sprite");
    sprite_t *d = malloc( dfs_size( fp ) );
    dfs_read( d, 1, dfs_size( fp ), fp );
    dfs_close( fp ); 
    
    fp = dfs_open("/l.sprite");
    sprite_t *l = malloc( dfs_size( fp ) );
    dfs_read( l, 1, dfs_size( fp ), fp );
    dfs_close( fp ); 
    
    fp = dfs_open("/r.sprite");
    sprite_t *r = malloc( dfs_size( fp ) );
    dfs_read( r, 1, dfs_size( fp ), fp );
    dfs_close( fp ); 
    
    fp = dfs_open("/ur.sprite");
    sprite_t *ur = malloc( dfs_size( fp ) );
    dfs_read( ur, 1, dfs_size( fp ), fp );
    dfs_close( fp ); 
    
    fp = dfs_open("/ul.sprite");
    sprite_t *ul = malloc( dfs_size( fp ) );
    dfs_read( ul, 1, dfs_size( fp ), fp );
    dfs_close( fp ); 
    
    fp = dfs_open("/dr.sprite");
    sprite_t *dr = malloc( dfs_size( fp ) );
    dfs_read( dr, 1, dfs_size( fp ), fp );
    dfs_close( fp ); 
    
    fp = dfs_open("/dl.sprite");
    sprite_t *dl = malloc( dfs_size( fp ) );
    dfs_read( dl, 1, dfs_size( fp ), fp );
    dfs_close( fp );
     
    fp = dfs_open("/m.sprite");
    sprite_t *m = malloc( dfs_size( fp ) );
    dfs_read( m, 1, dfs_size( fp ), fp );
    dfs_close( fp );
    
    /* Define Variables */
    int startscreen = 0;
    int stay = 0;
    int test = 1; 
       
    /* YX Axis */
    int xax = 120; 
	int yax = 120; 
	int zax = 120; 
    
    /* Graph */
    int upx = 0;
	int upy = 0;
	int uprightx = 0;
	int uprighty = 0;
	int rightx = 0;
	int righty = 0;
	int downrightx = 0;
	int downrighty = 0;
	int downx = 0;
	int downy = 0;
	int downleftx = 0;
	int downlefty = 0;
	int leftx = 0;
	int lefty = 0;
	int upleftx = 0;
	int uplefty = 0;

    /* Benchmark */
    int bupx = 0;
	int bupy = 0;
	int buprightx = 0;
	int buprighty = 0;
	int brightx = 0;
	int brighty = 0;
	int bdownrightx = 0;
	int bdownrighty = 0;
	int bdownx = 0;
	int bdowny = 0;
	int bdownleftx = 0;
	int bdownlefty = 0;
	int bleftx = 0;
	int blefty = 0;
	int bupleftx = 0;
	int buplefty = 0;
	int centers = 0;

	int results = 0; 
	
    /* Main loop */
    while(1)
    {
		/* Create Place for Keys */
		struct controller_data keys;	
		
		/* Create Place for Text */
		char tStr[256];
		
		/* Display Name */
        static display_context_t disp = 0;

        /* Grab a render buffer */
        while( !(disp = display_lock()) );
        		
        switch( startscreen )
        {
            case 0:	/* Neoflash Logo Screen */
       		{				
				/* fill screen */
				graphics_fill_screen( disp, 0 ); 
				
				/* Press Start Text */
				graphics_draw_text( disp, 120, 226, "PRESS START" );
			
				/* Neo Flash Logo */
				graphics_draw_sprite_trans( disp, 60, 8, neo );
			
				/* User input */
				controller_scan();		
				keys = get_keys_down();
			
				/* Go to main part of program */
				if( keys.c[0].start )
				{
					startscreen=1;
				}
				
				/* Go to credits */
				if( keys.c[0].A )
				{
					startscreen=4;
				}
				
			break;
			}
			
			case 1: /* Button Test */
			{			
				 /* fill screen */
				graphics_fill_screen( disp, 0 );
        			
				/* Write Name of Program and draw Logo */
				graphics_draw_text( disp, 110, 10, "Press a Button to Test" );
				graphics_draw_text( disp, 110, 20, "or move the Analog Stick" );
				graphics_draw_text( disp, 10, 210, "START skips" );
				graphics_draw_text( disp, 10, 220, "to next test" );
				graphics_draw_sprite_trans( disp, 110, 66, neo );
		
				/* User input */
				controller_scan();
				keys = get_keys_pressed(); 

				if( keys.c[0].up )
				{
					graphics_draw_text( disp, 10, 40, "DPAD Up pressed" );				
				}

				else if( keys.c[0].down )
				{
					graphics_draw_text( disp, 10, 40, "DPAD Down pressed" );	
				}
		
				else if( keys.c[0].left )
				{
					graphics_draw_text( disp, 10, 40, "DPAD Left pressed" );	
				}

				else if( keys.c[0].right )
				{
					graphics_draw_text( disp, 10, 40, "DPAD Right pressed" );	
				} 	
						
				else if( keys.c[0].A )
				{
					graphics_draw_text( disp, 10, 40, "A Button pressed" );	
				} 
				
				else if( keys.c[0].B )
				{
					graphics_draw_text( disp, 10, 40, "B Button pressed" );	
				}
			
				else if( keys.c[0].R )
				{
					graphics_draw_text( disp, 10, 40, "R Button pressed" );	
				} 
				
				else if( keys.c[0].L )
				{
					graphics_draw_text( disp, 10, 40, "L Button pressed" );	
				}
			
				else if( keys.c[0].C_up )
				{
					graphics_draw_text( disp, 10, 40, "C Up pressed" );				
				}

				else if( keys.c[0].C_down )
				{
					graphics_draw_text( disp, 10, 40, "C Down pressed" );	
				}
		
				else if( keys.c[0].C_left )
				{
					graphics_draw_text( disp, 10, 40, "C Left pressed" );	
				}

				else if( keys.c[0].C_right )
				{
					graphics_draw_text( disp, 10, 40, "C Right pressed" );	
				} 	
			
				else if( keys.c[0].Z )
				{
					graphics_draw_text( disp, 10, 40, "Z Button pressed" );	
				}
	
				if( keys.c[0].x )
				{
					sprintf(tStr, "X: %d  ", keys.c[0].x );
					graphics_draw_text( disp, 10, 60, tStr );	
				}

				if( keys.c[0].y )
				{
					sprintf(tStr, "Y: %d\n", keys.c[0].y );
					graphics_draw_text( disp, 10, 70, tStr );	
				} 	
						 	
				keys = get_keys_down();
				if( keys.c[0].start )
				{	
					startscreen=2;
				}
			break;
			}
			
			case 2: /* Diagram */
			{				
				xax = 120; /* midpoint x */
				yax = 120; /* midpoint y */
				zax = 120; /* size */
				
				controller_scan();
				keys = get_keys_pressed();
				
				if(stay==0)
				{	
					/* fill screen */
					graphics_fill_screen( disp, 0 );
									
					/* Draw Axis */
					graphics_draw_line(disp, xax-zax, yax, xax+zax, yax, graphics_make_color(255, 255, 255, 150));
					graphics_draw_line(disp, xax, yax-zax, xax, yax+zax, graphics_make_color(255, 255, 255, 150));
					graphics_draw_pixel(disp, xax, yax, graphics_make_color(0, 0, 0, 255));
					graphics_draw_pixel(disp, xax+80, yax, graphics_make_color(0, 0, 0, 255));
					graphics_draw_pixel(disp, xax-80, yax, graphics_make_color(0, 0, 0, 255));
					graphics_draw_pixel(disp, xax, yax+80, graphics_make_color(0, 0, 0, 255));
					graphics_draw_pixel(disp, xax, yax-80, graphics_make_color(0, 0, 0, 255));
					
					/* Draw Analog Stick Value */
					graphics_draw_text(disp, 250, 10, "ANALOG" );
					sprintf(tStr, "X: %d\n", keys.c[0].x );
					graphics_draw_text( disp, 250, 30, tStr );
					sprintf(tStr, "Y: %d\n", keys.c[0].y );
					graphics_draw_text( disp, 250, 40, tStr );
				}
				else
				{
					graphics_draw_pixel(disp, xax, yax, graphics_make_color(0, 255, 0, 255));
					graphics_draw_pixel(disp, xax+80, yax, graphics_make_color(0, 255, 0, 255));
					graphics_draw_pixel(disp, xax-80, yax, graphics_make_color(0, 255, 0, 255));
					graphics_draw_pixel(disp, xax, yax+80, graphics_make_color(0, 255, 0, 255));
					graphics_draw_pixel(disp, xax, yax-80, graphics_make_color(0, 255, 0, 255));	
				}
				
				graphics_draw_text(disp, 130, 210, "Press Z to change Mode" );
				graphics_draw_text(disp, 130, 220, "and START to Benchmark" );
				graphics_draw_sprite_trans( disp, 10, 186, leaf );
				
				/* Draw Analog Stick */
				graphics_draw_pixel(disp, xax+keys.c[0].x, yax-keys.c[0].y, graphics_make_color(255, 0, 0, 255));
					
				/* Go back to startscreen */
				keys = get_keys_down();
				if( keys.c[0].start )
				{	
					startscreen=3;
					stay=0;
				}	
				if( keys.c[0].Z )
				{	
					if(stay==1)
						stay=0;
					else 
						stay=1;
				}	
			break;
			}
			
			case 3: /* Benchmark */
			{
				/* fill screen */
				graphics_fill_screen( disp, 0 );
        			
				/* User input */
				controller_scan();
				keys = get_keys_pressed();
				
				switch( test )
				{
					
					case 0:	/* Display results */
					{
						switch(results)
						{
							case 0:
							{
								graphics_draw_text( disp, 20, 10, "Your Analog Stick Benchmark Results" );
								if(centers)
									graphics_draw_text( disp, 230, 90, "centers ok" );
								else
									graphics_draw_text( disp, 230, 90, "off center" );
							    upx = bupx;
								upy = bupy;
								uprightx = buprightx;
								uprighty = buprighty;
								rightx = brightx;
								righty = brighty;
								downrightx = bdownrightx;
								downrighty = bdownrighty;
								downx = bdownx;
								downy = bdowny;
								downleftx = bdownleftx;
								downlefty = bdownlefty;
								leftx = bleftx;
								lefty = blefty;
								upleftx = bupleftx;
								uplefty = buplefty;
								
								keys = get_keys_down();
								if( keys.c[0].A )
								{
									results=1;
								} 
								
							break;
							}
							case 1:
							{
								graphics_draw_text( disp, 60, 10, "New Original Analog Stick" );
							    upx = 1;
								upy = 84;
								uprightx = 67;
								uprighty = 68;
								rightx = 83;
								righty = -2;
								downrightx = 67;
								downrighty = -69;
								downx = 3;
								downy = -85;
								downleftx = -69;
								downlefty = -70;
								leftx = -85;
								lefty = 0;
								upleftx = -68;
								uplefty = 68;
								
								keys = get_keys_down();
								if( keys.c[0].A )
								{
									results=2;
								} 
								
							break;
							}
							case 2:
							{
								graphics_draw_text( disp, 160, 10, "LN64 Analog Stick" );
							    upx = 0;
								upy = 108;
								uprightx = 75;
								uprighty = 80;
								rightx = 112;
								righty = 0;
								downrightx = 77;
								downrighty = -75;
								downx = 0;
								downy = -105;
								downleftx = -69;
								downlefty = -75;
								leftx = -100;
								lefty = 0;
								upleftx = -67;
								uplefty = 84;
								
								keys = get_keys_down();
								if( keys.c[0].A )
								{
									results=3;
								} 
								
							break;
							}
							case 3:
							{
								graphics_draw_text( disp, 50, 10, "Fake OEM Style Analog Stick" );
							    upx = 3;
								upy = 92;
								uprightx = 69;
								uprighty = 75;
								rightx = 91;
								righty = -2;
								downrightx = 71;
								downrighty = -85;
								downx = -1;
								downy = -102;
								downleftx = -77;
								downlefty = -87;
								leftx = -90;
								lefty = -7;
								upleftx = -68;
								uplefty = 76;
																
								keys = get_keys_down();
								if( keys.c[0].A )
								{
									results=4;
								} 
								
							break;
							}
							case 4:
							{
								graphics_draw_text( disp, 80, 10, "GC Style Analog Stick" );
							    upx = 0;
								upy = 88;
								uprightx = 80;
								uprighty = 88;
								rightx = 88;
								righty = 0;
								downrightx = 80;
								downrighty = -88;
								downx = 0;
								downy = -88;
								downleftx = -88;
								downlefty = -88;
								leftx = -88;
								lefty = 0;
								upleftx = -88;
								uplefty = 88;
								
								keys = get_keys_down();
								if( keys.c[0].A )
								{
									results=5;
								} 
								
							break;
							}
							
							case 5:
							{
								graphics_draw_text( disp, 90, 10, "GC Style ATMEGA8" );
							    upx = 1;
								upy = 81;
								uprightx = 80;
								uprighty = 81;
								rightx = 80;
								righty = 1;
								downrightx = 80;
								downrighty = -70;
								downx = 1;
								downy = -78;
								downleftx = -79;
								downlefty = -70;
								leftx = -79;
								lefty = 1;
								upleftx = -79;
								uplefty = 81;
								
								keys = get_keys_down();
								if( keys.c[0].A )
								{
									results=0;
								} 
								
							break;
							}
						}
						sprintf(tStr, "UP: %d  ", upy );
						graphics_draw_text( disp, 230, 50, tStr );
						sprintf(tStr, "DOWN: %d  ", downy );
						graphics_draw_text( disp, 230, 60, tStr );
						sprintf(tStr, "LEFT: %d  ", leftx );
						graphics_draw_text( disp, 230, 70, tStr );
						sprintf(tStr, "RIGHT: %d  ", rightx );
						graphics_draw_text( disp, 230, 80, tStr );
						
						graphics_draw_text( disp, 230, 150, "Press A" );
						graphics_draw_text( disp, 230, 160, "to cycle" );
						graphics_draw_text( disp, 230, 170, "results" );
						
						graphics_draw_text( disp, 210, 210, "Compo 2012" );
						graphics_draw_text( disp, 210, 220, "NEOFLASH.COM" );
					
						xax = 120; /* midpoint x */
						yax = 120; /* midpoint y */
						zax = 120; /* size */
						
						graphics_draw_line(disp, xax+upx, yax-upy, xax+uprightx, yax-uprighty, graphics_make_color(255, 0, 0, 255));
						graphics_draw_line(disp, xax+uprightx, yax-uprighty, xax+rightx, yax-righty, graphics_make_color(255, 0, 0, 255));
						graphics_draw_line(disp, xax+rightx, yax-righty, xax+downrightx, yax-downrighty, graphics_make_color(255, 0, 0, 255));
						graphics_draw_line(disp, xax+downrightx, yax-downrighty, xax+downx, yax-downy, graphics_make_color(255, 0, 0, 255));
						graphics_draw_line(disp, xax+downx, yax-downy, xax+downleftx, yax-downlefty, graphics_make_color(255, 0, 0, 255));
						graphics_draw_line(disp, xax+downleftx, yax-downlefty, xax+leftx, yax-lefty, graphics_make_color(255, 0, 0, 255));
						graphics_draw_line(disp, xax+leftx, yax-lefty, xax+upleftx, yax-uplefty, graphics_make_color(255, 0, 0, 255));
						graphics_draw_line(disp, xax+upleftx, yax-uplefty, xax+upx, yax-upy, graphics_make_color(255, 0, 0, 255));
						
						graphics_draw_pixel(disp, xax, yax, graphics_make_color(255, 255, 255, 255));
						graphics_draw_pixel(disp, xax+80, yax, graphics_make_color(255, 255, 255, 255));
						graphics_draw_pixel(disp, xax-80, yax, graphics_make_color(255, 255, 255, 255));
						graphics_draw_pixel(disp, xax, yax+80, graphics_make_color(255, 255, 255, 255));
						graphics_draw_pixel(disp, xax, yax-80, graphics_make_color(255, 255, 255, 255));
						
					break;	
					}
					
					case 1:	/* +y Up */
					{	
						graphics_draw_text( disp, 10, 10, "To start the Benchmark" );
						graphics_draw_text( disp, 10, 20, "hold the Stick in it's most" );
						graphics_draw_text( disp, 10, 30, "upwards position and press A" );	
						graphics_draw_sprite_trans( disp, 110, 60, u );
						
						keys = get_keys_down();
						if( keys.c[0].A )
						{
							keys = get_keys_pressed();
							bupx = keys.c[0].x;
							bupy = keys.c[0].y;
							test=2;
						} 	
					break;
					}
					
					case 2:	/* +y+x Up-Right */
					{	
						graphics_draw_text( disp, 10, 10, "Now hold the Stick Up-Right" );
						graphics_draw_text( disp, 10, 20, "and press A" );	
						graphics_draw_sprite_trans( disp, 110, 60, ur );
						
						keys = get_keys_down();
						if( keys.c[0].A )
						{
							keys = get_keys_pressed();
							buprightx = keys.c[0].x;
							buprighty = keys.c[0].y;
							test=3;
						} 
					break;
					}
					
					case 3:	/* +x Right */
					{	
						graphics_draw_text( disp, 10, 10, "Now hold the Stick Right" );
						graphics_draw_text( disp, 10, 20, "and press A" );	
						graphics_draw_sprite_trans( disp, 110, 60, r );
						
						keys = get_keys_down();
						if( keys.c[0].A )
						{
							keys = get_keys_pressed();
							brightx = keys.c[0].x;
							brighty = keys.c[0].y;
							test=4;
						} 	
					break;
					}
					
					case 4:	/* -y+x Down-Right*/
					{		
						graphics_draw_text( disp, 10, 10, "Now hold the Stick Down-Right" );
						graphics_draw_text( disp, 10, 20, "and press A" );	
						graphics_draw_sprite_trans( disp, 110, 60, dr );
											
						keys = get_keys_down();
						if( keys.c[0].A )
						{
							keys = get_keys_pressed();
							bdownrightx = keys.c[0].x;
							bdownrighty = keys.c[0].y;
							test=5;
						} 	
					break;
					}
					
					case 5:	/* -y Down*/
					{	
						graphics_draw_text( disp, 10, 10, "Now hold the Stick Down" );
						graphics_draw_text( disp, 10, 20, "and press A" );	
						graphics_draw_sprite_trans( disp, 110, 60, d );
					
						keys = get_keys_down();
						if( keys.c[0].A )
						{
							keys = get_keys_pressed();
							bdownx = keys.c[0].x;
							bdowny = keys.c[0].y;
							test=6;
						} 		
					break;
					}
					
					case 6:	/* -y-x Down-Left */
					{	
						graphics_draw_text( disp, 10, 10, "Now hold the Stick Down-Left" );
						graphics_draw_text( disp, 10, 20, "and press A" );	
						graphics_draw_sprite_trans( disp, 110, 60, dl );
					
						keys = get_keys_down();
						if( keys.c[0].A )
						{
							keys = get_keys_pressed();
							bdownleftx = keys.c[0].x;
							bdownlefty = keys.c[0].y;
							test=7;
						} 		
					break;
					}
					
					case 7:	/* -x Left */
					{	
						graphics_draw_text( disp, 10, 10, "Now hold the Stick Left" );
						graphics_draw_text( disp, 10, 20, "and press A" );	
						graphics_draw_sprite_trans( disp, 110, 60, l );
					
						keys = get_keys_down();
						if( keys.c[0].A )
						{
							keys = get_keys_pressed();
							bleftx = keys.c[0].x;
							blefty = keys.c[0].y;
							test=8;
						} 		
					break;
					}
					
					case 8:	/* +y+x Up-Left */
					{	
						graphics_draw_text( disp, 10, 10, "Now hold the Stick Up-Left" );
						graphics_draw_text( disp, 10, 20, "and press A" );	
						graphics_draw_sprite_trans( disp, 110, 60, ul );
											
						keys = get_keys_down();
						if( keys.c[0].A )
						{
							keys = get_keys_pressed();
							bupleftx = keys.c[0].x;
							buplefty = keys.c[0].y;
							test=9;
						} 		
					break;
					}
					
					case 9:	/* center */
					{	
						graphics_draw_text( disp, 10, 10, "Now let go of the" );
						graphics_draw_text( disp, 10, 20, "Stick and press A" );
						graphics_draw_sprite_trans( disp, 110, 60, m );	
					
						keys = get_keys_down();
						if( keys.c[0].A )
						{
							keys = get_keys_pressed();
							if (keys.c[0].x<3 && keys.c[0].x>-3 && keys.c[0].y<3 && keys.c[0].y>-3)
								centers=1;
							else
								centers=0;
							test=0;
						} 		
					break;
					}	
				}
				graphics_draw_text( disp, 10, 210, "Press" );
				graphics_draw_text( disp, 10, 220, "START to end" );
				if(test!=0)
					graphics_draw_sprite_trans( disp, 230, 186, leaf );
					
				/* Go back to startscreen */
				keys = get_keys_down();
				if( keys.c[0].start )
				{	
					startscreen=0;
					test = 1;
					centers = 0;
					results = 0;
				}	
			break;
			} 
			
			case 4:	/* credits */
       		{
				/* fill screen */
				graphics_fill_screen( disp, 0 );
        			
				/* credits */
				graphics_draw_text( disp, 10, 10, "Credits" );
				graphics_draw_text( disp, 10, 30, "ControllerTest made 2012 by sanni" );
				graphics_draw_text( disp, 10, 40, "programmed with libdragon" );
				graphics_draw_text( disp, 10, 60, "Thanks to:" );
				graphics_draw_text( disp, 10, 70, "Shaun Taylor" );
				graphics_draw_text( disp, 10, 80, "Dr.neo" );
				graphics_draw_text( disp, 10, 90, "ChillyWilly" );
				graphics_draw_text( disp, 10, 100, "marshallh" );
				graphics_draw_text( disp, 10, 220, "Press START" );
				graphics_draw_sprite_trans( disp, 110, 66, neo );
		
				/* User input */
				controller_scan();
				keys = get_keys_down();
				if( keys.c[0].start )
				{	
					startscreen=0;
				}		
			break;
			}
			
		} /* main menu switch */
		 
		/* Show display */
		display_show(disp);
		
	} /* while 1*/
} /* main */
