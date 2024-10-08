#include <GL/glut.h>

// �׸��� �Լ�
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // ȭ��� ���� ���� �ʱ�ȭ

    // ī�޶� ���� (ī�޶� ��ġ�� z�� �ڷ� �̵�)
    glLoadIdentity();
    gluLookAt(0.0, 0.0, 5.0,  // ī�޶� ��ġ (x, y, z)
        0.0, 0.0, 0.0,  // ī�޶� �ٶ󺸴� ���� (x, y, z)
        0.0, 1.0, 0.0); // �� ���� (x, y, z)

    // ť�긦 �׸��� ����
    glBegin(GL_QUADS);

    // Front face
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);

    // Back face
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);

    // Left face
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);

    // Right face
    glVertex3f(1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);

    // Top face
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);

    // Bottom face
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);

    glEnd();

    glutSwapBuffers(); // ���� ���۸��� ����Ͽ� ȭ�� ����
}

// ������ �������� �� ȣ��Ǵ� �Լ�
void reshape(int width, int height) {
    glViewport(0, 0, width, height);  // ���ο� ������ ũ�� ����

    glMatrixMode(GL_PROJECTION);      // ���� ��ķ� ����
    glLoadIdentity();
    gluPerspective(45.0, (double)width / (double)height, 1.0, 100.0); // ���� ���� ����
    glMatrixMode(GL_MODELVIEW);       // �ٽ� �𵨺� ��ķ� ����
}

// ���� �Լ�
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("OpenGL Cube");

    glEnable(GL_DEPTH_TEST); // ���� �׽�Ʈ Ȱ��ȭ

    glutDisplayFunc(display);
    glutReshapeFunc(reshape); // ������ ũ�� ���� �� ȣ��Ǵ� �Լ� ����

    glutMainLoop();

    return 0;
}
