#include "gl/glut.h"
#include <cstdio>
#include <ctime>
#include <queue>

// ť���� ���� ������
GLfloat vertices[] = {
    -1.0f, -1.0f, -1.0f, // Vertex 0
    1.0f, -1.0f, -1.0f,  // Vertex 1
    1.0f,  1.0f, -1.0f,  // Vertex 2
    -1.0f,  1.0f, -1.0f, // Vertex 3
    -1.0f, -1.0f,  1.0f, // Vertex 4
    1.0f, -1.0f,  1.0f,  // Vertex 5
    1.0f,  1.0f,  1.0f,  // Vertex 6
    -1.0f,  1.0f,  1.0f   // Vertex 7
};

// ť���� �� ����(���� �ε���)
GLubyte indices[] = {
    0, 1, 2, 3, // Front face
    4, 5, 6, 7, // Back face
    0, 1, 5, 4, // Bottom face
    2, 3, 7, 6, // Top face
    0, 3, 7, 4, // Left face
    1, 2, 6, 5  // Right face
};

// �޽� �ʱ�ȭ
void InitMyMesh() {
    // Vertex Buffer Object (VBO)�� �����մϴ�.
    GLuint vboVertices;
    glGenBuffers(1, &vboVertices);

    // VBO�� ���� �����͸� �����մϴ�.
    glBindBuffer(GL_ARRAY_BUFFER, vboVertices);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // Element Buffer Object (EBO)�� �����մϴ�.
    GLuint eboIndices;
    glGenBuffers(1, &eboIndices);

    // EBO�� �ε��� �����͸� �����մϴ�.
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, eboIndices);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    // ���� �迭�� Ȱ��ȭ�մϴ�.
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, nullptr);
}

// �׸��� �Լ�
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // ť�긦 �׸��ϴ�.
    glDrawElements(GL_QUADS, sizeof(indices) / sizeof(GLubyte), GL_UNSIGNED_BYTE, nullptr);

    glutSwapBuffers();
}

// ���� �Լ�
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("OpenGL Cube");

    glEnable(GL_DEPTH_TEST); // ���� �׽�Ʈ Ȱ��ȭ
    InitMyMesh(); // �޽� �ʱ�ȭ

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
