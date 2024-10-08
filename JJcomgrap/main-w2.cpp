#include "cstdio"
#include "cmath"
#include "gl/glut.h"

/* Global variables and structures. */
int arrowNum0 = 0;
int arrowNum1 = 0;
int pageNum = 0;
int timeIdx = 0;
bool isAnimation = false;
struct Point {
    float x, y;
};
struct Line {
    Point p0, p1;
};
struct Box {
    Point min, max;
};
struct Circle {
    Point center;
    float radius;
};

/* Function prototypes. */
bool CircleCircleCollision(Circle c0, Circle c1);
bool BoxBoxCollision(Box b0, Box b1);
bool PointInBox(Point pt, Box box);
bool PointInCircle(Point pt, Circle circle);

void DrawPoint(Point p);
void DrawLine(Line l);
void DrawBox(Box b, bool isFill);
void DrawCircle(Circle c, bool isFill);

void F7();
void F8();
void F9();
void F10();
void F11();
void F12();

/* Callback function prototypes. */
void display();
void keyboard(unsigned char key, int x, int y);
void mouse(int button, int state, int x, int y);
void motion(int x, int y);
void special(int key, int x, int y);
void entry(int state);
void idle();
void timer(int value);

/* Main function. */
int main(int argc, char **argv)
{
    /* GLUT initializations. */
    glutInit(&argc, argv);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(500, 500);

    glutInitDisplayMode(GLUT_RGB);
    glutCreateWindow("AIE305 Computer Graphics");

    /* Call back functions. */
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutSpecialFunc(special);
    glutEntryFunc(entry);

    /* Main loop. */
    glutMainLoop();

    return 0;
}

/* Callback functions. */
void display()
{
    printf("ArrowNum0 %d ArrowNum1 %d\n", arrowNum0, arrowNum1);

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);  
    glLoadIdentity();
    glOrtho(-10, 10, -10, 10, -10, 10);   // 직교투영

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glColor3f(0.0f, 0.0f, 1.0f); // 0.0 ~ 1.0, Red, Green, Blue

    /* 1. Draw a sphere. */
    //glutWireSphere(1.0, 20, 20);       //glutWireSphere(1.0, 20 + arrowNum0, 20 + arrowNum1);
    /*glutSolidSphere(1.0, 20, 20);*/

    /* 2. Draw a cube. */
    /*glutWireCube(10.0)*/;
    //glutSolidCube(10.0);

    /* 3. Draw a cone. */
    /*glutWireCone(1.0, 2.0, 20, 20);*/

    /* 4. Draw a torus with rotation. */
    /*glRotatef((float)arrowNum0, 1.0, 0.0, 0.0);
    glutWireTorus(2.5, 5.0, 20, 20);*/

    /* 5. Draw a teapot with TRS. */
    //glTranslatef((float)arrowNum1, 0.0, 0.0);
    //glRotatef((float)arrowNum0, 1.0, 0.0, 0.0);
    //glScalef(1.0 + arrowNum0 * 0.1, 1.0, 1.0);
    //glutWireTeapot(1.0);

    /* 6. Draw a teapot with rotation and translation. */
    //glMatrixMode(GL_MODELVIEW);
    //float rotateAngle = (float) arrowNum0;
    ///* Rotate-Translate (red) */
    //glLoadIdentity();
    //glColor3f(1, 0, 0);
    //glRotatef(rotateAngle, 0.0, 0.0, 1.0);
    //glTranslatef(1.0, 0.0, 0.0);
    //glutWireTeapot(1.0);

    ///* Translate-Rotate (blue) */
    //glColor3f(0, 0, 1);
    //glLoadIdentity();
    //glTranslatef(1.0, 0.0, 0.0);
    //glRotatef(rotateAngle, 0.0, 0.0, 1.0);
    //glutWireTeapot(1.0);

    /* 7. Point in box. */
    //F7();

    /* 8. Point in circle. */
    //F8();

    /* 9. Circle-Crcle collision. */
    //F9();

    /* 10. Box-Box collision. */
    //F10();

    /* 11. (HW) Solar systems. */
    F11();

    /* 12. (HW) Point in triangle. */
    //F12();

    glFinish();
}

void keyboard(unsigned char key, int x, int y)
{
    if (key == 27) // ESC
	exit(0);
    else if (key == 'a') {
	isAnimation = !isAnimation;
	glutTimerFunc(10, timer, 0);
    }
}

void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
	printf("Mouse left button is pressed at (%d, %d)\n", x, y);
    }

}

void motion(int x, int y)
{
    printf("Mouse is moving at (%d, %d)\n", x, y);
}

void special(int key, int x, int y)
{
    if (key == GLUT_KEY_F1)
	printf("F1 key is pressed at (%d, %d)\n", x, y);
    else if (key == GLUT_KEY_UP)
	arrowNum0++;
    else if (key == GLUT_KEY_DOWN)
	arrowNum0--;
    else if (key == GLUT_KEY_LEFT)
	arrowNum1--;
    else if (key == GLUT_KEY_RIGHT)
	arrowNum1++;
    else if (key == GLUT_KEY_PAGE_UP)
	pageNum++;
    else if (key == GLUT_KEY_PAGE_DOWN)
	pageNum--;

    glutPostRedisplay();
}

void entry(int state)
{
    if (state == GLUT_ENTERED)
	printf("Mouse entered the window\n");
    else if (state == GLUT_LEFT)
	printf("Mouse left the window\n");
}

void idle()
{
    printf("Idle function is called\n");
}

void timer(int value)
{
    if (isAnimation) {
	glutTimerFunc(10, timer, 0);
	timeIdx += 1;
	glutPostRedisplay();
    }
}

bool BoxBoxCollision(Box b0, Box b1)
{
    if (b0.max.x < b1.min.x || b1.max.x < b0.min.x)
	return false;

    if (b0.max.y < b1.min.y || b1.max.y < b0.min.y)
	return false;

    return true;
}

bool CircleCircleCollision(Circle c0, Circle c1)
{
    float
	circleDist = sqrt(pow(c0.center.x - c1.center.x, 2) +
			  pow(c0.center.y - c1.center.y, 2));

    if (circleDist > c0.radius + c1.radius)
	return false;
    else
	return true;
}

bool PointInBox(Point pt, Box box)
{
    if (pt.x >= box.min.x && pt.x <= box.max.x &&
	pt.y >= box.min.y && pt.y <= box.max.y)
	return true;
    else
	return false;
}

bool PointInCircle(Point pt, Circle circle)
{
    float dx = pt.x - circle.center.x;
    float dy = pt.y - circle.center.y;
    float distance = sqrt(dx * dx + dy * dy);
    if (distance <= circle.radius)
	return true;
    else
	return false;
}

void DrawPoint(Point p)
{
    glBegin(GL_POINTS);
    glVertex2d(p.x, p.y);
    glEnd();
}

void DrawLine(Line l)
{
    glBegin(GL_LINES);
    glVertex2d(l.p0.x, l.p0.y);
    glVertex2d(l.p1.x, l.p1.y);
    glEnd();
}

void DrawBox(Box b, bool isFill)
{
    if (isFill)
	glBegin(GL_POLYGON);
    else
	glBegin(GL_LINE_LOOP);

    glVertex2f(b.min.x, b.min.y);
    glVertex2f(b.max.x, b.min.y);
    glVertex2f(b.max.x, b.max.y);
    glVertex2f(b.min.x, b.max.y);
    glEnd();
}

void DrawCircle(Circle c, bool isFill)
{
    if (isFill)
	glBegin(GL_POLYGON);
    else
	glBegin(GL_LINE_LOOP);

    for (int i = 0; i < 360; i++) {
	float angle = i * 3.141592 / 180.0;
	float x = c.center.x + c.radius * cos(angle);
	float y = c.center.y + c.radius * sin(angle);
	glVertex2f(x, y);
    }
    glEnd();
}

void F7()
{
    Box box = {{float(arrowNum1), float(arrowNum0)},
	       {float(arrowNum1 + 2 + pageNum), float(arrowNum0 + 2 + pageNum)}};

    glLineWidth(1.0);
    DrawBox(box, false);

    glPointSize(2);
    for (int i = 0; i <= 100; i++) {
	for (int j = 0; j <= 100; j++) {
	    Point pt = {-10 + float(0.2 * i), -10 + float(0.2 * j)};
	    if (PointInBox(pt, box))
		glColor3f(1, 0, 0);
	    else
		glColor3f(0, 0, 0);
	    glBegin(GL_POINTS);
	    glVertex2f(pt.x, pt.y);
	    glEnd();
	}
    }
}

void F8()
{
    Circle circle{{float(arrowNum1), float(arrowNum0)}, float(pageNum + 2)};
    glLineWidth(3.0);
    DrawCircle(circle, false);

    glPointSize(2);
    for (int i = 0; i <= 100; i++) {
	for (int j = 0; j <= 100; j++) {
	    Point pt = {-10 + float(0.2 * i), -10 + float(0.2 * j)};
	    if (PointInCircle(pt, circle))
		glColor3f(1, 0, 0);
	    else
		glColor3f(0, 0, 0);
	    glBegin(GL_POINTS);
	    glVertex2f(pt.x, pt.y);
	    glEnd();
	}
    }
}

void F9()
{
    Circle circle0 = {{float(arrowNum1), float(arrowNum0)}, 2};
    Circle circle1 = {{-4,0}, 1.0 + 0.1 * pageNum};

    bool isFill = CircleCircleCollision(circle0, circle1);

    if (isFill)
	glColor3f(1, 0, 0);
    else
	glColor3f(0, 1, 0);

    DrawCircle(circle0, isFill);
    DrawCircle(circle1, isFill);
}

void F10()
{
    Box box0 = {{float(arrowNum1), float(arrowNum0)},
	       {float(arrowNum1 + 2 + pageNum * 0.1),
		float(arrowNum0 + 2 + pageNum * 0.1)}};
    Box box1 = {{-3, -3}, {-1, -1}};

    bool isFill = BoxBoxCollision(box0, box1);

    glLineWidth(1.0);

    if (isFill)
	glColor3f(1, 0, 0);
    else
	glColor3f(0, 1, 0);

    DrawBox(box0, isFill);
    DrawBox(box1, isFill);
}

void F11() /* Homework. Solar Systems. */
{
    //Sun
    glPushMatrix();
    glColor3f(1, 0, 0);
    DrawCircle({{0,0}, 2.0}, 3.0);

    //Earth
    glPushMatrix();
    glRotated(timeIdx / 365.0 * 360.0, 0, 0, 1);
    glTranslated(7, 0.0, 0.0);
    glColor3f(0, 0, 1);
    DrawCircle({{0,0}, 1.0}, 1.0);

    //Moon	
    glPushMatrix();
    glRotated(timeIdx / 27.0 * 360.0, 0, 0, 1);
    glTranslated(1.5, 0.0, 0.0);
    glColor3f(1, 0, 1);
    DrawCircle({{0,0}, 0.2}, 0.3);

    glPopMatrix(); // for Moon
    glPopMatrix(); // for Earth
    glPopMatrix(); // for Sun

    //Mars

    //Jupiter

    //Saturn

    //Titan
}

void F12() /* Homework. Do test for point in triangle. */
{
    glPointSize(2);
    for (int i = 0; i <= 100; i++) {
	for (int j = 0; j <= 100; j++) {
	    Point pt = {-10 + float(0.2 * i), -10 + float(0.2 * j)};

	    /* Do something here! */

	    glBegin(GL_POINTS);
	    glVertex2f(pt.x, pt.y);
	    glEnd();
	}
    }
}