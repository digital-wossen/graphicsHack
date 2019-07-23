/*
Computer Graphis 2019
Problem 2.3
<Wossen> <Hailemariam>
w.hailemariam@jaobs-university.de
*/


#include <GL/glut.h>

#include <stdlib.h>
#include <stdio.h>
#include <iostream>

#define checkImageWidth 64
#define checkImageHeight 64
static GLubyte checkImage[checkImageHeight][checkImageWidth][4];

static GLuint texName[4];

unsigned int figure_num = 0;

void makeCheckImage(void)
{
    int i, j, c;
    
    for (i = 0; i < checkImageHeight; i++) {
        for (j = 0; j < checkImageWidth; j++) {
            c = ((((i&0x8)==0)^((j&0x8))==0))*255;
            checkImage[i][j][0] = (GLubyte) c;
            checkImage[i][j][1] = (GLubyte) c;
            checkImage[i][j][2] = (GLubyte) c;
            checkImage[i][j][3] = (GLubyte) 255;
        }
    }
}

void init(void)
{
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
    glEnable(GL_DEPTH_TEST);
    
    makeCheckImage();
    glGenTextures(4, texName);
    
    
    
    switch (figure_num) {
        case 0:
            glBindTexture(GL_TEXTURE_2D, texName[figure_num]);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); 
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); 
            
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, checkImageWidth,
                        checkImageHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE,
                        checkImage);
            break;
        case 1:
            glBindTexture(GL_TEXTURE_2D, texName[figure_num]);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); 
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); 
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); 
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, checkImageWidth,
                        checkImageHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE,
                        checkImage);
            break;
        case 2:
            glBindTexture(GL_TEXTURE_2D, texName[figure_num]);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); 
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, checkImageWidth,
                        checkImageHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE,
                        checkImage);
            break;
        case 3:
            glBindTexture(GL_TEXTURE_2D, texName[figure_num]);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE); 
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); 
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); 
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, checkImageWidth,
                        checkImageHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE,
                        checkImage);
            break;
    }

    
    
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glEnable(GL_TEXTURE_2D);
    

    // upper right
    init();

    glBegin(GL_POLYGON);
    glTexCoord2f(-0.125, -1); glVertex3f(0.0, 0.0, 0.0);
    glTexCoord2f(0, -1);      glVertex3f(1.0, 2.0, 0.0);
    glTexCoord2f(-0.0625, 1); glVertex3f(2.0, 0.0, 0.0);

    figure_num = ( figure_num + 1 ) % 2;
    glEnd();
    
    glFlush();
    

    // Upper left
    init();

    glBegin(GL_POLYGON);

    glTexCoord2f(-3.0, 1.0); glVertex3f(-3.0, 0.0, 0.0);
    glTexCoord2f(-2.0, 2.0); glVertex3f(-3.0, 2.0, 0.0);
    glTexCoord2f(-2.0, 1.0); glVertex3f(-1.0, 2.0, 0.0);

    glTexCoord2f(-2.0, 1.0); glVertex3f(-3.0, 0.0, 0.0);
    glTexCoord2f(-2.0, 2.0); glVertex3f(-1.0, 0.0, 0.0);
    glTexCoord2f(-1.0, 2.0); glVertex3f(-1.0, 2.0, 0.0);

    figure_num = ( figure_num + 1 ) % 2;

    glEnd();
    
    glFlush();


    // lower left
    init();

    glBegin(GL_POLYGON);

    glTexCoord2f(-2.0, -2.0); glVertex3f(-2.0, -2.5, 0.0);
    glTexCoord2f(-1.0, -1.0); glVertex3f(-2.0, -0.5, 0.0);
    glTexCoord2f(-1.0, -2.0); glVertex3f(0.0, -0.5, 0.0);

    glTexCoord2f(-1.0, -2.0); glVertex3f(-2.0, -2.5, 0.0);
    glTexCoord2f(-1.0, -1.0); glVertex3f(0.0, -2.5, 0.0);
    glTexCoord2f(0.0, -1.0); glVertex3f(0.0, -0.5, 0.0);

    figure_num = ( figure_num + 1 ) % 2;

    glEnd();
    
    glFlush();
    

    // lower right
    init();

    glBegin(GL_POLYGON);

    glTexCoord2f(-2.0, -2.0); glVertex3f(0.0, -2.5, 0.0);
    glTexCoord2f(-1.0, -1.0); glVertex3f(0.0, -0.5, 0.0);
    glTexCoord2f(-1.0, -2.0); glVertex3f(2.0, -0.5, 0.0);

    glTexCoord2f(-1.0, -2.0); glVertex3f(0.0, -2.5, 0.0);
    glTexCoord2f(-1.0, -1.0); glVertex3f(2.0, -2.5, 0.0);
    glTexCoord2f(0.0, -1.0); glVertex3f(2.0, -0.5, 0.0);

    figure_num = ( figure_num + 1 ) % 2;

    glEnd();
    
    glFlush();
    
}


void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (GLfloat) w/(GLfloat) h, 1.0, 30.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -3.6);
}

void keyboard (unsigned char key, int x, int y)
{
    switch (key) {
        case 27:
            exit(0);
            break;
        default:
            break;
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0; 
}
