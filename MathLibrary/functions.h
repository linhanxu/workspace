#ifndef FUNCTIONS_H
#define FUNCTIONS_H


#include <OpenMesh/Core/IO/MeshIO.hh>
#include <OpenMesh/Core/Mesh/TriMesh_ArrayKernelT.hh>
#include <OpenMesh/Core/Mesh/Handles.hh>
#define EIGEN_NO_DEBUG 
#include <unsupported/Eigen/MatrixFunctions>
#include <Eigen/Dense>
#include <Eigen/Sparse>
#include <Eigen/SparseLU>
#include <Eigen/SparseCholesky>
#include <Eigen/Cholesky>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include<cmath>

using namespace std;
using namespace Eigen;

class functions
{
	typedef OpenMesh::TriMesh_ArrayKernelT<> PGMesh;
	typedef Eigen::VectorXd VectorXd;
	typedef PGMesh::EdgeHandle EdgeHandle;
	typedef PGMesh::VertexHandle VertexHandle;

protected:
	struct faceanchor
	{
		int frameNo;
		int idx;
		Eigen::Matrix3d localframe;
	};
	struct vertexanchor
	{
		int frameNo;
		int idx;
		Eigen::VectorXd cord;
	};


public:
	/**��ʼ��*/
	functions(PGMesh *_mesh, int meshNum);
	~functions();

	PGMesh *mesh_;//�ο�����
	int nSeq;//���е�֡��
	int nV;//��ĸ���
	int nF;//��ĸ���
	int nE;//�ߵĸ���	
	
	Eigen::MatrixXd DiEdgeDataMatrix;//�����߸�֡�Ķ���Ǻͱ߳�
	vector<vector<double>> FaceAreas;//�������֡�����
	//vector<vector<double>> de;//de[��][֡]��de=(1/3)*(a1+a2)���Ա�e��Ϊ�����ߵ����������֮�͵�����֮һ
	vector<vector<Eigen::VectorXd>> SpatialTemData;//���������֡������
	vector<vector<Eigen::Vector3d>> FaceNormals;//�������֡�ķ�����	
	vector<vector<Eigen::Matrix3d>> FaceLocalFrames;//�������֡�ľֲ����

	std::vector<unsigned int> edgeanchors_;//��ê������
	std::vector<unsigned int> Vertexanchors_;//����ê������
	std::vector<unsigned int> Faceanchors_;//��ê������
	int anchorPointidx;//ê���index
	int anchorEidx;//ê����ڱߵ�index
	std::vector<std::vector<faceanchor>> faceAnchorFrames;//����ÿ֡��ê��ı��
	std::vector<std::vector<vertexanchor>> vertexAnchorCords;//����ÿ֡��ê�������
	SimplicialCholesky<Eigen::SparseMatrix<double>> presolver;
	Eigen::SparseMatrix<double> vertexCoff;

	VertexHandle POINT0_HANDLE(EdgeHandle edgeHandle) { return mesh_->from_vertex_handle(mesh_->halfedge_handle(edgeHandle, 0)); }
	VertexHandle POINT1_HANDLE(EdgeHandle edgeHandle) { return mesh_->to_vertex_handle(mesh_->halfedge_handle(edgeHandle, 0)); }
	VectorXd POINT(VertexHandle vertexhandle, int frame) { return SpatialTemData[vertexhandle.idx()][frame]; }
	VectorXd EDGE_POINT0(EdgeHandle edgeHandle, int frame) { return POINT(POINT0_HANDLE(edgeHandle), frame); }
	VectorXd EDGE_POINT1(EdgeHandle edgeHandle, int frame) { return POINT(POINT1_HANDLE(edgeHandle), frame); }
	VectorXd VECTOR(EdgeHandle edgeHandle, int frame) { return EDGE_POINT1(edgeHandle, frame) - EDGE_POINT0(edgeHandle, frame); }
	Eigen::Vector3d computeCross(Eigen::Vector3d x1, Eigen::Vector3d x2)//���
	{
		Eigen::Vector3d x;
		x(0) = x1(1) * x2(2) - x1(2) * x2(1);
		x(1) = -x1(0) * x2(2) + x2(0) * x1(2);
		x(2) = x1(0) * x2(1) - x1(1) * x2(0);
		return x;
	}
	/** ����ê��*/
	void functions::setAnchor(unsigned int _idx);
	/** ����������֡������Լ�ÿ����ķ�����*/
	void calculateFacesAreas();
	/** ����������֡�ķ�����*/
	void calculateFacesNormals();
	/** ���㵥֡������ķ�����*/
	Eigen::Vector3d calculateFaceNormal(int faceNo, int frameNo);
	/** ���㵥֡������ľֲ����*/
	faceanchor calculateFaceFrame(int faceNo, int frameNo);
	/** ����������֡�ľֲ����*/
	void calculateFacesFrame();
	/** ��������߸�֡�Ķ���Ǻͱ߳�*/
	void computeDiEdge();
	/** ���ݶ���Ǻͱ߳��ع�����*/
	void functions::reconstructionFromDiEdges(Eigen::VectorXd edgeComponent, Eigen::VectorXd & cordComponent, int anchorIthSeq, double radius, int ithComp);
	/** ���ݵ����굼��obj����*/
	void functions::outMesh(Eigen::VectorXd cordComponent, char* path);
	/** ���ݵ����굼��off����*/
	void functions::outMesh1(Eigen::VectorXd cordComponent, string path);
	/** �Ƚ�presolver*/
	void presolve();
};
#endif // FUNCTIONS_H
