/*
Computer Graphis 2019
Problem 2.1
<Wossen> <Hailemariam>
w.hailemariam@jaobs-university.de
*/




#include <GL/glut.h>  // GLUT, include glu.h and gl.h

/* Global variables */
char title[] = "3D Shapes";
static float xAxis = 1.5;
static float yAxis = 0;
static float zAxis = -7;
static float xAngle = 0;
static float yAngle = 0;
static float zAngle = 0;

/* Initialize OpenGL Graphics */
void initGL() {
   glClearColor(0.0f, 0.0f, 0.0f, 0.1f); // Set background color to black and opaque
   glClearDepth(0.0f);                   // Set background depth to farthest
   glEnable(GL_DEPTH_TEST);   // Enable depth testing for z-culling
   glDepthFunc(GL_LEQUAL);    // Set the type of depth-test
   glShadeModel(GL_SMOOTH);   // Enable smooth shading
   glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  // Nice perspective corrections
}

/* Handler for window-repaint event. Called back when the window first appears and
   whenever the window needs to be re-painted. */
void display() {
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
   glMatrixMode(GL_MODELVIEW);     // To operate on model-view matrix

  glLoadIdentity();                 // Reset the model-view matrix
   glTranslatef(xAxis, yAxis, zAxis);  // Move right and into the screen
   glRotatef(xAngle, 1.0f, 0.0f, 0.0f);
   glRotatef(yAngle, 0.0f, 1.0f, 0.0f);
   glRotatef(zAngle, 0.0f, 0.0f, 1.0f);

  
glLoadIdentity();
   /* glBegin(GL_QUADS);//head
      glColor3f (0.0f, 1.0f, 0.0f);

      glVertex3f (0.2, 0.5, 0.3);
      glVertex3f (-0.2, 0.5, 0.03);
      glVertex3f (-0.2, 0.9, 0.6);
      glVertex3f (0.2, 0.9, 0.7);
*/
     glBegin(GL_QUADS);                // Begin drawing the color cube with 6 quads
      // Top face (y = 1.0f)
      // Define vertices in counter-clockwise (CCW) order with normal pointing out
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f( 0.2f, 0.5f, -0.2f);
      glVertex3f(-0.2f, 0.5f, -0.2f);
      glVertex3f(-0.2f, 0.9f,  0.2f);
      glVertex3f( 0.2f, 0.9f,  0.2f);

      // Bottom face (y = -1.0f)
      glColor3f(1.0f, 0.5f, 0.0f);     // Orange
      glVertex3f( 0.2f, 0.5f,  0.2f);
      glVertex3f(-0.2f, 0.5f,  0.2f);
      glVertex3f(-0.2f, 0.9f, -0.2f);
      glVertex3f( 0.2f, 0.9f, -0.2f);

      // Front face  (z = 1.0f)
      glColor3f(1.0f, 0.0f, 0.0f);     // Red
      glVertex3f( 0.2f, 0.5f, 0.2f);
      glVertex3f(-0.2f, 0.5f, 0.2f);
      glVertex3f(-0.2f, 0.9f, 0.2f);
      glVertex3f( 0.2f, 0.9f, 0.2f);

      // Back face (z = -1.0f)
      glColor3f(1.0f, 1.0f, 0.0f);     // Yellow
      glVertex3f( 0.2f, 0.5f, -0.2f);
      glVertex3f(-0.2f, 0.5f, -0.2f);
      glVertex3f(-0.2f, 0.9f, -0.2f);
      glVertex3f( 0.2f, 0.9f, -0.2f);

      // Left face (x = -1.0f)
      glColor3f(0.0f, 0.0f, 1.0f);     // Blue
      glVertex3f(-0.2f,  0.5f,  0.2f);
      glVertex3f(-0.2f,  0.5f, -0.2f);
      glVertex3f(-0.2f,  0.9f, -0.2f);
      glVertex3f(-0.2f,  0.9f,  0.2f);

      // Right face (x = 1.0f)
      glColor3f(1.0f, 0.0f, 1.0f);     // Magenta
      glVertex3f(0.2f,  0.5f, -0.2f);
      glVertex3f(0.2f,  0.5f,  0.2f);
      glVertex3f(0.2f,  0.9f,  0.2f);
      glVertex3f(0.2f,  0.9f, -0.2f);
   glEnd();  // End of drawing color-cube
//this shit don't work ... I am done
            // Reset the model-view matrix
   
    glEnd();
     glBegin(GL_QUADS);//neck
      glColor3f (0.0f, 1.0f, 0.0f);

      glVertex3f (0.1, 0.5, 0.0);
      glVertex3f (-0.1, 0.5, 0.0);
      glVertex3f (-0.1, 0.3, 0.0);
      glVertex3f (0.1, 0.3, 0.0);
    
    
    glEnd();
     
     glBegin(GL_QUADS);//torso
      glColor3f (0.0f, 1.0f, 0.0f);

      glVertex3f (0.3, 0.3, 0.0);
      glVertex3f (-0.3, 0.3, 0.0);
      glVertex3f (-0.3, -0.4, 0.0);
      glVertex3f (0.3, -0.4, 0.0);
    
    
    glEnd();

     glBegin(GL_QUADS);//left_leg
      glColor3f (0.0f, 1.0f, 0.0f);

      glVertex3f (0.3, -0.4, 0.0);
      glVertex3f (0.1, -0.4, 0.0);
      glVertex3f (0.1, -0.9, 0.0);
      glVertex3f (0.3, -0.9, 0.0);
    
    
    glEnd();
     glBegin(GL_QUADS);//right_leg
      glColor3f (0.0f, 1.0f, 0.0f);

      glVertex3f (-0.3, -0.4, 0.0);
      glVertex3f (-0.1, -0.4, 0.0);
      glVertex3f (-0.1, -0.9, 0.0);
      glVertex3f (-0.3, -0.9, 0.0);

      glEnd();

     glBegin(GL_QUADS);//left_hand
      glColor3f (0.0f, 1.0f, 0.0f);

      glVertex3f (0.4, 0.3, 0.0);
      glVertex3f (0.4, 0.3, 0.0);
      glVertex3f (0.5, -0.2, 0.0);
      glVertex3f (0.5, -0.7, 0.0);
    
    
    glEnd();
     glBegin(GL_QUADS);//right_hand
      glColor3f (0.0f, 1.0f, 0.0f);

      glVertex3f (-0.4, 0.3, 0.0);
      glVertex3f (-0.4, 0.3, 0.0);
      glVertex3f (-0.5, -0.2, 0.0);
      glVertex3f (-0.5, -0.7, 0.0);
    
    
    glEnd();


    glFlush();
    glutSwapBuffers();  
    glTranslatef(-1.5f, 0.0f, -6.0f);  // Move left and into the screen
}

int main(int argc, char** argv) {
   glutInit(&argc, argv);            // Initialize GLUT
   glutInitDisplayMode(GLUT_DOUBLE); // Enable double buffered mode
   glutInitWindowSize(640, 880);   // Set the window's initial width & height
   glutInitWindowPosition(50, 80); // Position the window's initial top-left corner
   glutCreateWindow(title);          // Create window with the given title
   glutDisplayFunc(display);       // Register callback handler for window re-paint event
   initGL();                       // Our own OpenGL initialization
   glutMainLoop();                 // Enter the infinite event-processing loop

   return 0;
}
