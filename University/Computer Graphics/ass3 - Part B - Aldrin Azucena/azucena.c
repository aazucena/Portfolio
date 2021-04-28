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
bool isCube = true, isPyr = true, isSph = true;
float Cube_Rot = 0.0f, Pyr_Rot = 0.0f, Sph_Rot = 0.0f;
float Z_Rot = 0.0f;  // Initially only rotate around X-axis. the rotation.
float Z_Off = 1.0f;

float nudgeBy = 5.0f;

// LookAt position and rotation
float x = 0.0f, y = 0.0f, z = 0.0f;
float xEye = 0.0f, yEye = 0.0f, zEye = 0.0f; //position in that plane 
float xAt = 0.0f, yAt= 0.0f, zAt = 0.0f; // vector that represents the camera's direction
float xUp = 0.0f, yUp = 0.0f, zUp = 0.0f;




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
   
   // Clear the color and depth buffers.
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glEnable(GL_DEPTH_TEST);

   // Need to manipulate the ModelView matrix to move our model around.
   glMatrixMode(GL_MODELVIEW);

   // Reset to 0,0,0; no rotation, no scaling.
   glLoadIdentity(); 

   // Set camera
   gluLookAt(xEye, yEye, zEye+5.0f,
                xAt, 0, zAt,
                0, 1, 0);

   // Rotate the calculated amount.
   //glTranslatef(-X_Off,0.0f,0.0f);
   glTranslatef(0.0f,0.0f,0.0f);
   glRotatef(Cube_Rot, 0.0f, 0.0f, 1.0f);
   // Drawing Cube
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

   // All polygons have been drawn from cube.
   glEnd();


   // Move back to the origin
   glLoadIdentity();

   // Set camera
   gluLookAt(xEye, yEye, zEye+5.0f,
                xAt, 0, zAt,
                0, 1, 0);

   // Rotate the calculated amount.
   //glTranslatef(-X_Off,0.0f,0.0f);
   glTranslatef(0.0f,0.0f, -5.0f);
   glRotatef(Pyr_Rot, 0.0f, 0.0f, 1.0f);
   glTranslatef(0.0f,0.0f, 0.0f);
   
   // Drawing Pyramid
   glBegin(GL_TRIANGLES); 
   
   //Front
   glColor4f(0.2f, 0.9f, 0.2f, 0.0f); 

   glVertex3f( 0.0f, 1.0f, 0.0f);
   glVertex3f(-1.0f, -1.0f, 1.0f);
   glVertex3f( 1.0f, -1.0f, 1.0f);

   //Right
   glColor4f(0.2f, 0.2f, 0.9f, 0.0f);

   glVertex3f( 0.0f,  1.0f,  0.0f); 
   glVertex3f( 1.0f, -1.0f,  1.0f);
   glVertex3f( 1.0f, -1.0f, -1.0f);

   //Back
   glColor4f(0.9f, 0.2f, 0.2f, 0.0f);
   
   glVertex3f( 0.0f,  1.0f,  0.0f);
   glVertex3f( 1.0f, -1.0f, -1.0f);
   glVertex3f(-1.0f, -1.0f, -1.0f); 

   //Left
   glColor4f(0.9f, 0.9f, 0.2f, 0.0f);
   
   glVertex3f( 0.0f,  1.0f,  0.0f);
   glVertex3f(-1.0f, -1.0f, -1.0f);
   glVertex3f(-1.0f, -1.0f,  1.0f);
   

   // Bottom face - Pink
   glNormal3f(0.0f, 0.0f, 0.0f);
   glColor4f(0.9f, 0.75f, 0.8f, 0.0f);
   
   glVertex3f( 1.0f, -1.0f,  1.0f);
   glVertex3f(-1.0f, -1.0f,  1.0f);
   glVertex3f(-1.0f, -1.0f, -1.0f); 

   glNormal3f(0.0f, 0.0f, 0.0f);
   glColor4f(0.9f, 0.75f, 0.8f, 0.0f);
   
   glVertex3f(-1.0f, -1.0f, -1.0f);
   glVertex3f( 1.0f, -1.0f, -1.0f);
   glVertex3f( 1.0f, -1.0f,  1.0f); 

   // All polygons have been drawn from cube.
   glEnd();
   glLoadIdentity(); 

   GLUquadricObj* obj = gluNewQuadric();

   // Set camera
   gluLookAt(xEye, yEye, zEye+5.0f,
                xAt, 0, zAt,
                0, 1, 0);

   glPushMatrix();
      glTranslatef(5.0f,0.0f, -10.0f);
      glRotatef(Sph_Rot, 0.0f, 0.0f, 1.0f);
      glColor4f(1.0f, 1.0f, 1.0f, 0.0f);
      glutWireSphere(2.0f, 30, 36); //show if the sphere is rotating
      glColor4f(0.27f, 0.33f, 0.62f, 0.0f);
      gluSphere(obj, 2.0f, 100, 100);
   glPopMatrix();

    gluDeleteQuadric(obj);

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
   case 'q':
      isCube = false;
      isPyr = false; 
      isSph = false;
      break;   
   case 'a': //a
      isCube = false;
      isPyr = true; 
      isSph = true;
      break;
   case 'z': //z
      isCube = true;
      isPyr = true; 
      isSph = false;
      break;
   case 32: //SPACEBAR
      isCube = true;
      isPyr = true; 
      isSph = true;
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

   if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
      xEye = -nudgeBy;
      yEye = nudgeBy;
      zEye = nudgeBy;
   } else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
      xEye = 0;
      yEye = 0;
      zEye = 0;
   }  
   if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN){
      xEye = nudgeBy;
      yEye = nudgeBy;
      zEye = nudgeBy;
   } else if (button == GLUT_RIGHT_BUTTON && state == GLUT_UP) {
      xEye = 0;
      yEye = 0;
      zEye = 0;
   }   
   outputCoordinates();

}

void CallTimer(int) {
   glutPostRedisplay();
   glutTimerFunc(1000/60, CallTimer, 0);
   Z_Rot = Z_Rot + Z_Off;
   Cube_Rot = (isCube == true) ? Z_Rot : 0.0f;
   Pyr_Rot = (isPyr == true) ? Z_Rot : 0.0f;
   Sph_Rot = (isSph == true) ? Z_Rot : 0.0f;
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
   glEnable(GL_DEPTH_TEST);
   glDepthFunc(GL_LESS); 
   
   glEnable(GL_CULL_FACE);
   glCullFace(GL_BACK); 

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
   glutTimerFunc(1000/60, CallTimer, 0);

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