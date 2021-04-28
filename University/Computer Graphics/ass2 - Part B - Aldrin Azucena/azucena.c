#define PROGRAM_TITLE "Assignment 2 - Part B"
#define DISPLAY_INFO "Aldrin Azucena - 001220471"
#include <iostream> // output results of the cube and lookat coordinates
#include <windows.h>
#include <stdlib.h>  // Useful for the following includes.
#include <stdio.h>    
#include <math.h>  // For math operations.
#include <string.h>  // For string operations.

#include <GL/gl.h>   // OpenGL itself.
#include <GL/glu.h>  // GLU support library.
#include <GL/glut.h> // GLUT support library.

// Some global variables.
// Window IDs, window width and height.
int Window_ID;
int Window_Width = 600;
int Window_Height = 400;

// Cube position and rotation speed variables.
float X_Rot   = 0.0f;  // Initially only rotate around X-axix.
float Y_Rot   = 0.0f;  // Later on you can use control keys to change
float X_Speed = 0.0f;  // the rotation.
float Y_Speed = 0.01f;
float Z_Speed = 0.01f;
float X_Off   = 0.0f;
float Z_Off   = 0.0f;

float nudgeBy = 5.0f;
// LookAt position and rotation
float x = 0.0f, y = 0.0f, z = 0.0f;
float xEye = 0.0f, yEye = 0.0f, zEye = -5.0f; //position in that plane 
float xAt = 0.0f, yAt= 0.0f, zAt = 0.0f; // vector that represents the camera's direction
float xUp = 0.0f, yUp = 0.0f, zUp = 0.0f;
float angle = 30.0f;
int timer = 0;



/////////////////////////////////////////////////////////////
// Outputs coordinates of the lookat from the key trigger 
/////////////////////////////////////////////////////////////
void outputCoordinates() {
   std::cout << "(" 
   << xEye << ", "
   << yEye << ", "
   << zEye 
   << "), (" 
   << xAt << ", "
   << yAt << ", "
   << zAt 
   << "), (" 
   << xUp << ", "
   << yUp << ", "
   << zUp 
   << ")" << std::endl;
   std::cout << "--------------------" << std::endl;
}

//////////////////////////////////////////////////////////
// String rendering routine; leverages on GLUT routine. //
//////////////////////////////////////////////////////////
static void PrintString(void *font, char *str)
{
   int i,len=strlen(str);

   for(i=0;i < len; i++)
      glutBitmapCharacter(font,*str++);
}

/////////////////////////////////////////////////////////
// Routine which actually does the drawing             //
/////////////////////////////////////////////////////////
void CallBackRenderScene(void)
{
   char buf[80]; // For our strings.
   
   // Need to manipulate the ModelView matrix to move our model around.
   glMatrixMode(GL_MODELVIEW);

   // Reset to 0,0,0; no rotation, no scaling.
   glLoadIdentity(); 

   // Set camera
      gluLookAt(xEye, yEye, zEye,
                xAt, 0, zAt,
                0, 1, 0);

   // Rotate the calculated amount.
   //glTranslatef(-X_Off,0.0f,0.0f);
   glTranslatef(0.0f,0.0f,0.0f);
   glRotatef(Y_Rot, 0.0f, 1.0f,0.0f);
   glTranslatef(0.0f,0.0f,0.0f);
   //glRotatef(Y_Rot,0.0f,0.5f,0.0f);

   // Clear the color and depth buffers.
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glEnable(GL_DEPTH_TEST);

   // OK, let's start drawing our planer quads.
   glBegin(GL_QUADS); 

   // Far face.  Green, 50% opaque, non-uniform texture cooridinates.
   glNormal3f(0.0f, 0.0f, 0.0f);
   glColor4f(0.2f, 0.9f, 0.2f, 0.0f); 

   glVertex3f(-1.0f, -1.0f, -1.0f);
   glVertex3f(-1.0f,  1.0f, -1.0f);
   glVertex3f( 1.0f,  1.0f, -1.0f);
   glVertex3f( 1.0f, -1.0f, -1.0f);

   // Right face.  Blue; 25% opaque   
   glNormal3f(0.0f, 0.0f, 0.0f);
   glColor4f(0.2f, 0.2f, 0.9f, 0.0f);

   glVertex3f( 1.0f, -1.0f, -1.0f); 
   glVertex3f( 1.0f,  1.0f, -1.0f);
   glVertex3f( 1.0f,  1.0f,  1.0f);
   glVertex3f( 1.0f, -1.0f,  1.0f);

   // Front face; offset.  Multi-colored, 50% opaque.
   glNormal3f(0.0f, 0.0f, 0.0f);
   glColor4f(0.9f, 0.2f, 0.2f, 0.0f);
   
   glVertex3f(-1.0f, -1.0f,  1.0f);
   glVertex3f( 1.0f, -1.0f,  1.0f);
   glVertex3f( 1.0f,  1.0f,  1.0f); 
   glVertex3f(-1.0f,  1.0f,  1.0f);


   // Left Face; offset.  Yellow, varying levels of opaque.
   glNormal3f(0.0f, 0.0f, 0.0f);
   glColor4f(0.9f, 0.9f, 0.2f, 0.0f);
   
   glVertex3f(-1.0f, -1.0f, -1.0f); 
   glVertex3f(-1.0f, -1.0f,  1.0f);
   glVertex3f(-1.0f,  1.0f,  1.0f);
   glVertex3f(-1.0f,  1.0f, -1.0f);

   
   // Top face - Cyan
   glNormal3f(0.0f, 0.0f, 0.0f);
   glColor4f(0.0f, 0.9f, 0.9f, 0.0f);
   
   glVertex3f( 1.0f, 1.0f,  -1.0f);
   glVertex3f(-1.0f, 1.0f,  -1.0f);
   glVertex3f(-1.0f, 1.0f,  1.0f); 
   glVertex3f( 1.0f, 1.0f,  1.0f);

   
   // Bottom face - Pink
   glNormal3f(0.0f, 0.0f, 0.0f);
   glColor4f(0.9f, 0.75f, 0.8f, 0.0f);
   
   glVertex3f( 1.0f, -1.0f,  1.0f);
   glVertex3f(-1.0f, -1.0f,  1.0f);
   glVertex3f(-1.0f, -1.0f, -1.0f); 
   glVertex3f( 1.0f, -1.0f, -1.0f);



   // All polygons have been drawn.
   glEnd();

   // Move back to the origin
   glLoadIdentity();

   // We need to change the projection matrix for the text rendering.  
   glMatrixMode(GL_PROJECTION);

   // But we like our current view too; so we save it here.
   glPushMatrix();


   // Display a string
   // Now we set up a new projection for the text.
   glLoadIdentity();
   glOrtho(0,Window_Width,0,Window_Height, -50.0, 50.0);
   glColor4f(0.6,1.0,0.6,1.00);
   sprintf(buf,"%s", DISPLAY_INFO); // Print the string into a buffer
   glRasterPos2i(2,2);                         // Set the coordinate
   PrintString(GLUT_BITMAP_HELVETICA_12, buf);  // Display the string.

   
   // To ease, simply translate up.  Note we're working in screen
   // pixels in this projection.
   glTranslatef(6.0f, Window_Height - 14, 0.0f);

   // Done with this special projection matrix.  Throw it away.
   glPopMatrix();
   glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);

   // We start with GL_DECAL mode.
   glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_DECAL);

   // All done drawing.  Let's show it.
   glutSwapBuffers();

   // Now let's do the motion calculations.

   if (timer < 30) {
      Y_Rot += 0;
      timer++;
   } else {
      Y_Rot += angle;
   }
}


/////////////////////////////////////////////////////////////
// Callback Function called when pressing ‘a’ pushes the cube 
// forward (away from you) while pressing ‘z’ retreats the cube 
// backward (back toward you).
/////////////////////////////////////////////////////////////
void myControlKey(unsigned char key, int x, int y) 
{
   std::cout << "From key: " << key;
   switch (key)
   {
   case 'a': //a
      zEye -= nudgeBy;
      zAt -= nudgeBy;
      outputCoordinates();
      break;
   case 'z': //z
      zEye += nudgeBy;
      zAt += nudgeBy;
      outputCoordinates();
      break;
   default:
      printf ("No action for %d.\n", key);
      break;
   }
}

/////////////////////////////////////////////////////////////
// Callback Function called when a special key is pressed. //
/////////////////////////////////////////////////////////////
void myControlMouse(int button, int state, int x, int y) {
   //float fraction = 0.1f;
   static float prevZ = 0.0f; 

   if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
      prevZ = zEye;
      xEye = nudgeBy;
      yEye = nudgeBy;
      zEye = nudgeBy;
   } else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
      xEye = 0;
      yEye = 0;
      zEye = prevZ;
   }  
   if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN){
      xEye = nudgeBy;
      yEye = nudgeBy;
   } else if (button == GLUT_RIGHT_BUTTON && state == GLUT_UP) {
      xEye = 0;
      yEye = 0;
   }   
   outputCoordinates();

}


///////////////////////////////////////////////////////////////
// Callback routine executed whenever the window is resized. //
//////////////////////////////////////////////////////////////
void CallBackResizeScene(int Width, int Height)
{
   // Let's not core dump, no matter what.
   if (Height == 0)
      Height = 1;

   glViewport(0, 0, Width, Height);

   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluPerspective(45.0f,(GLfloat)Width/(GLfloat)Height,0.1f,100.0f);

   glMatrixMode(GL_MODELVIEW);

   Window_Width  = Width;
   Window_Height = Height;
}

////////////////////////////////////////////////////////
//   Setup your program before passing the control    //
//   to the main OpenGL event loop.                   //
////////////////////////////////////////////////////////
void MyInit(int Width, int Height) 
{
   // Color to clear color buffer to.
   glClearColor(0.1f, 0.1f, 0.1f, 0.0f);

   // Depth to clear depth buffer to; type of test.
   glClearDepth(1.0);
   glDepthFunc(GL_LESS); 

   // Enables Smooth Color Shading; try GL_FLAT for (lack of) fun.
   glShadeModel(GL_SMOOTH);

   // Load up the correct perspective matrix; using a callback directly.
   CallBackResizeScene(Width,Height);
}

///////////////////////////////////////////////////
// main() function.                              //
//   There are general steps in making           //
//   an OpenGL application.                      //
//   Inits OpenGL.                               //
//   Calls our own init function                 //
//   then passes control onto OpenGL.            //   
///////////////////////////////////////////////////
int main(int argc, char **argv)
{
   glutInit(&argc, argv);
   
   // To see OpenGL drawing, take out the GLUT_DOUBLE request.
   glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);

   // The following is for window creation.
   // Set Window size
   glutInitWindowSize(Window_Width, Window_Height);
   // Create and Open a window with its title.
   Window_ID = glutCreateWindow(PROGRAM_TITLE);

   // Register and install the callback function to do the drawing. 
   glutDisplayFunc(&CallBackRenderScene);

   // If there's nothing to do, draw.
   glutIdleFunc(&CallBackRenderScene);

   // It's a good idea to know when our window's resized.
   glutReshapeFunc(&CallBackResizeScene);

   // Register and install the callback function for
   // Some keys and special keys.
   glutKeyboardFunc(&myControlKey);
   glutMouseFunc(&myControlMouse);

   // OK, OpenGL's ready to go.  Let's call our own init function.
   MyInit(Window_Width, Window_Height);

   // Print out a bit of help dialog.
   printf("\n%s\n\n", PROGRAM_TITLE);
   printf("Print out some helpful information here.\n");
   printf("When you program, you can also use\n");
   printf("printf to do debugging.\n\n");

   // Above functions represents those you will do to set up your
   // application program.
   // Now pass off control to OpenGL.
   glutMainLoop(); 
   // Never returns.
   return 1; 
}