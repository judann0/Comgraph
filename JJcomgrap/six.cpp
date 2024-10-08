#include <cstdio>
#include <vector>
#include <gl/glut.h>

#include <GL/GCAABBBVH.h>

#include <string>
#include <fstream>
#include <iostream>
#include <cmath>



// 구조체 정의
struct Vec3 {
    float x, y, z;
};

class Mesh {
public:
    std::vector<Vec3> vertices;
    std::vector<std::array<int, 3>> faces;

    void add_vertex(float x, float y, float z) {
        vertices.push_back({ x, y, z });
    }

    void add_face(int v1, int v2, int v3) {
        faces.push_back({ v1, v2, v3 });
    }

    void write(const std::string& filename) {
        std::ofstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Error opening file: " << filename << std::endl;
            return;
        }

        // Write vertices
        for (const auto& v : vertices) {
            file << "v " << v.x << " " << v.y << " " << v.z << "\n";
        }

        // Write faces
        for (const auto& f : faces) {
            file << "f " << f[0] + 1 << " " << f[1] + 1 << " " << f[2] + 1 << "\n";
        }

        file.close();
        std::cout << "Mesh successfully saved to " << filename << std::endl;
    }
};

// Function to initialize the mesh with a cube of size 2
void InitMyMesh(Mesh& mesh) {
    // Define the vertices of a cube with size 2 centered at the origin
    std::vector<Vec3> vertices = {
        {-1.0f, -1.0f, -1.0f},  // 0
        {1.0f, -1.0f, -1.0f},   // 1
        {1.0f, 1.0f, -1.0f},    // 2
        {-1.0f, 1.0f, -1.0f},   // 3
        {-1.0f, -1.0f, 1.0f},    // 4
        {1.0f, -1.0f, 1.0f},     // 5
        {1.0f, 1.0f, 1.0f},      // 6
        {-1.0f, 1.0f, 1.0f}      // 7
    };

    // Add vertices to the mesh
    for (const auto& vertex : vertices) {
        mesh.add_vertex(vertex.x, vertex.y, vertex.z);
    }

    // Define the faces of the cube (two triangles for each face)
    std::vector<std::array<int, 3>> faces = {
        {0, 1, 2}, {0, 2, 3},  // front face
        {4, 5, 6}, {4, 6, 7},  // back face
        {0, 3, 7}, {0, 7, 4},  // left face
        {1, 5, 6}, {1, 6, 2},  // right face
        {3, 2, 6}, {3, 6, 7},  // top face
        {0, 4, 5}, {0, 5, 1}   // bottom face
    };

    // Add faces to the mesh
    for (const auto& face : faces) {
        mesh.add_face(face[0], face[1], face[2]);
    }
}

int main() {
    Mesh mesh;

    // Initialize the mesh with a cube
    InitMyMesh(mesh);

    // Write the mesh to an OBJ file
    mesh.write("output.obj");

    return 0;
}
