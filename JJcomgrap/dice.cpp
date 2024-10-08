#include "gl/glut.h"
#include <cstdio>
#include <ctime>
#include <queue>

// 큐브의 정점 데이터
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

// 큐브의 면 구성(정점 인덱스)
GLubyte indices[] = {
    0, 1, 2, 3, // Front face
    4, 5, 6, 7, // Back face
    0, 1, 5, 4, // Bottom face
    2, 3, 7, 6, // Top face
    0, 3, 7, 4, // Left face
    1, 2, 6, 5  // Right face
};

// 메쉬 초기화
void InitMyMesh() {
    // Vertex Buffer Object (VBO)를 생성합니다.
    GLuint vboVertices;
    glGenBuffers(1, &vboVertices);

    // VBO에 정점 데이터를 복사합니다.
    glBindBuffer(GL_ARRAY_BUFFER, vboVertices);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // Element Buffer Object (EBO)를 생성합니다.
    GLuint eboIndices;
    glGenBuffers(1, &eboIndices);

    // EBO에 인덱스 데이터를 복사합니다.
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, eboIndices);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    // 정점 배열을 활성화합니다.
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, nullptr);
}

// 그리기 함수
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // 큐브를 그립니다.
    glDrawElements(GL_QUADS, sizeof(indices) / sizeof(GLubyte), GL_UNSIGNED_BYTE, nullptr);

    glutSwapBuffers();
}

// 메인 함수
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("OpenGL Cube");

    glEnable(GL_DEPTH_TEST); // 깊이 테스트 활성화
    InitMyMesh(); // 메쉬 초기화

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
