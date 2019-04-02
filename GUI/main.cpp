#pragma once
#include "MathLibrary/functions.h"
#include <tapkee/tapkee.hpp>
#include "MathLibrary/d_vector2.h"
#include "MathLibrary/d_triangle.h"
#include "MathLibrary/d_delaunay.h"
#include "global.h"
#include "Workspace.h"
#include <QApplication>
#include <QGLFormat>
#include <QApplication>
#include <QDesktopWidget>

using namespace std;
using namespace tapkee;
typedef OpenMesh::TriMesh_ArrayKernelT<> PGMesh;
static const char MODEL[] = /*"body"*/"handstand"/*"man"*/;
const int meshNum = 5;//��֪�Ĺؼ�֡����
int nE_ = 0, nF_ = 0, nV_ = 0;//ģ�͵ı�����������������
double weights_0 = 0, weights_1 = 0, weights_2 = 0, weights_3 = 0, weights_4 = 0;//���Ȩ��,��СΪmeshNum

Eigen::MatrixXd DihEdgs_key;//��֪mesh�ĸ����߸�֡�Ķ���Ǻͱ߳�
Eigen::MatrixXd Dihs_key;//��֪mesh�ĸ����߸�֡�Ķ����
Eigen::MatrixXd Edgs_key;//��֪mesh�ĸ����߸�֡�ı߳�
Eigen::MatrixXd FaceAreas_key;//��֪mesh�ĸ�֡����������
Eigen::MatrixXd Points_key;//��֪mesh�ĸ������֡����ά����
/*
//int K = (meshNum - 1)*(n_ + 1);//P116ҳ��������Ĵ�С,������0-K��mesh����һ��K+1��
//Eigen::SparseMatrix<double> linSysMatrice(K + 1, K + 1);//P116ҳ�ľ���
*/
vector<vector<vector<float>>> d_triangles;
vector<vector<float>> d_points;
Eigen::MatrixXd DihEdg_blend;//���Ի����֪mesh�ĸ����߸�֡�Ķ���Ǻͱ߳�


void getNum_EFV()
{
	char *meshpath = new char[100];
	sprintf_s(meshpath, 100, "Resources\\inMesh\\%s_0.obj", MODEL);
	PGMesh *pg = new PGMesh();
	OpenMesh::IO::read_mesh(*pg, meshpath);

	functions *calcu = new functions(pg, meshNum);

	nE_ = calcu->nE;
	nF_ = calcu->nF;
	nV_ = calcu->nV;
}
void getDihEdgeArea()
{
	DihEdgs_key = Eigen::MatrixXd::Zero(2 * nE_, meshNum);
	Points_key = Eigen::MatrixXd::Zero(3 * nV_, meshNum);
	Dihs_key = Eigen::MatrixXd::Zero(nE_, meshNum);
	Edgs_key = Eigen::MatrixXd::Zero(nE_, meshNum);
	FaceAreas_key = Eigen::MatrixXd::Zero(nF_, meshNum);

	cout << "load mesh...\n";
	cout << "calculate dihedral angle��edge length and face area...\n";

	//�����Ǻͱ߳�	
	char *DihEdgDataPath = new char[100];
	sprintf_s(DihEdgDataPath, 100, "Resources\\data\\%s_DihEdgs.txt", MODEL);
	fstream opDE(DihEdgDataPath, ios::out);
	//�涥����ά����	
	char *PointsPath = new char[100];
	sprintf_s(PointsPath, 100, "Resources\\data\\%s_Points.txt", MODEL);
	fstream opPoints(PointsPath, ios::out);
	//�ֱ�����Ǻͱ߳�	
	char *DihDataPath = new char[100];
	sprintf_s(DihDataPath, 100, "Resources\\data\\%s_Dihs.txt", MODEL);
	fstream opD(DihDataPath, ios::out);
	char *EdgDataPath = new char[100];
	sprintf_s(EdgDataPath, 100, "Resources\\data\\%s_Edgs.txt", MODEL);
	fstream opE(EdgDataPath, ios::out);
	/*�����
	char *FaceAreasPath = new char[100];
	sprintf_s(FaceAreasPath, 100, "Resources\\data\\%s_FaceAreas.txt",MODEL);
	fstream opFA(FaceAreasPath, ios::out);*/

	for (int i = 0; i < meshNum; i++)
	{
		char *meshpath = new char[100];
		sprintf_s(meshpath, 100, "Resources\\inMesh\\%s_%d.obj", MODEL, i);
		PGMesh *pg = new PGMesh();
		OpenMesh::IO::read_mesh(*pg, meshpath);

		functions *calcu = new functions(pg, meshNum);
		calcu->calculateFacesNormals();
		calcu->calculateFacesFrame();
		calcu->computeDiEdge();

		DihEdgs_key.col(i) = calcu->DiEdgeDataMatrix.row(i).transpose();

		for (int j = 0, k = 0; j <nV_, k<3 * nV_; j++)
		{
			Points_key(k, i) = calcu->SpatialTemData[j][0][0];
			Points_key(k + 1, i) = calcu->SpatialTemData[j][0][1];
			Points_key(k + 2, i) = calcu->SpatialTemData[j][0][2];

			k = k + 3;
		}

		for (int j = 0; j<nE_; j++)
		{
			Dihs_key(j, i) = calcu->DiEdgeDataMatrix(0, 2 * j);
			Edgs_key(j, i) = calcu->DiEdgeDataMatrix(0, 2 * j + 1);
		}
		/*
		calcu->calculateFacesAreas();
		for (int j = 0; j < nF_; j++)
		{
		FaceAreas_key(j,i) = calcu->FaceAreas[j][i];
		}*/

		delete calcu;
		delete pg;
	}
	opDE << DihEdgs_key << endl;
	opDE.close();
	opPoints << Points_key << endl;
	opPoints.close();
	opD << Dihs_key << endl;
	opD.close();
	opE << Edgs_key << endl;
	opE.close();
	/*opFA << FaceAreas_key;
	opFA.close();*/
}

//��ά��2*nE_ά��2ά
tapkee::DenseMatrix  dimReduction()
{
	cout << "dimensionality reduction...\n";
	const int ROW = 2 * nE_;
	//const int ROW = 3*nV_;
	//const int ROW = nE_;
	const int COL = meshNum;
	tapkee::DenseMatrix matrix_before_dimReduction = tapkee::DenseMatrix::Zero(ROW, COL);

	ifstream infile;
	char *path = new char[100];
	//sprintf_s(path, 100, "Resources\\data\\%s_DihEdgs.txt", MODEL);
	sprintf_s(path, 100, "Resources\\data\\%s_Points.txt", MODEL);
	//sprintf_s(path, 100, "Resources\\data\\%s_Dih.txt", MODEL);
	//sprintf_s(path, 100, "Resources\\data\\%s_Edg.txt", MODEL);
	infile.open(path);
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			infile >> matrix_before_dimReduction(i, j);
		}
	}
	infile.close();

	TapkeeOutput output = tapkee::initialize::initialize()
		//.withParameters((method = KernelLocallyLinearEmbedding,
		.withParameters((method = KernelLocalTangentSpaceAlignment,
		//.withParameters((method = Isomap,
			num_neighbors = 4,
			target_dimension = 2))
		.embedUsing(matrix_before_dimReduction);
	return output.embedding.transpose();
}

//�����ʷ�
void d_delaunay()
{
	tapkee::DenseMatrix matrix_after_dimReduction = dimReduction();
	//�潵ά�������	
	char *dimReductionPath = new char[100];
	sprintf_s(dimReductionPath, 100, "Resources\\data\\%s_after_dimReduction.txt", MODEL);
	fstream opDE(dimReductionPath, ios::out);
	opDE << matrix_after_dimReduction << endl;

	std::cout << "delaunay triangulation...\n";
	vector<Vector2<float> > points;
	for (int i = 0; i < meshNum; i++) 
	{
		points.push_back(Vector2<float>(matrix_after_dimReduction(0, i), matrix_after_dimReduction(1, i)));
		vector<float> tmp;
		tmp.push_back(matrix_after_dimReduction(0, i));
		tmp.push_back(matrix_after_dimReduction(1, i));
		d_points.push_back(tmp);
	}	
	Delaunay<float> triangulation;
	const std::vector<Triangle<float> > triangles = triangulation.triangulate(points);
	std::cout << triangles.size() << "triangles generated\n";
	for (int i = 0; i < triangles.size(); i++)
	{
		vector<vector<float>> tmp0;//һ�������ε�������	
		vector<float> tmp1, tmp2, tmp3;
		tmp1.push_back(triangles[i].p1.x);tmp1.push_back(triangles[i].p1.y);
		tmp2.push_back(triangles[i].p2.x);tmp2.push_back(triangles[i].p2.y);
		tmp3.push_back(triangles[i].p3.x);tmp3.push_back(triangles[i].p3.y);
		tmp0.push_back(tmp1);
		tmp0.push_back(tmp2);
		tmp0.push_back(tmp3);			
		d_triangles.push_back(tmp0);
	}
	
	const std::vector<Edge<float> > edges = triangulation.getEdges();
	std::cout << " ========= ";

	std::cout << "\nPoints : " << points.size() << std::endl;
	for (const auto &p : triangles)  
		std::cout << p << std::endl;

	std::cout << "\nTriangles : " << triangles.size() << std::endl;
	for (const auto &t : triangles)
		std::cout << t << std::endl;

	/*std::cout << "\nEdges : " << edges.size() << std::endl;
	for (const auto &e : edges)
		std::cout << e << std::endl;*/
}

int main(int argc, char *argv[])
{
	getNum_EFV();
	getDihEdgeArea();
	d_delaunay();

	
	
	
	
	
	
	QApplication a(argc, argv);

	DEFAULT_FILE_PATH = "G:/VS2015_projects/workspace/Resources/inMesh";

	// Anti-aliasing
	QGLFormat glf = QGLFormat::defaultFormat();
	glf.setSamples(8);
	QGLFormat::setDefaultFormat(glf);

	// Create main window
	Workspace w;
	w.move(QApplication::desktop()->availableGeometry().center() - w.rect().center());
	w.show();
	w.addNewScene();



	return a.exec();

	getchar();
	return 0;

}


