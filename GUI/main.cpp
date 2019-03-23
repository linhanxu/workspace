#pragma once
#include "MathLibrary/functions.h"
#include <tapkee/tapkee.hpp>

#include "global.h"
#include "Workspace.h"
#include <QApplication>
#include <QGLFormat>
#include <QApplication>
#include <QDesktopWidget>



using namespace std;
using namespace tapkee;

//全局变量定义开始*********************************************************************************//
typedef OpenMesh::TriMesh_ArrayKernelT<> PGMesh;
static const char MODEL[] = "man";
const int meshNum = 5;//已知的关键帧个数

int nE_ = 0, nF_ = 0, nV_ = 0;//模型的边数、面数、顶点数
double weights_0 = 0, weights_1 = 0, weights_2 = 0, weights_3 = 0, weights_4 = 0;//混合权重,大小为meshNum

Eigen::MatrixXd DihEdgs_key;//已知mesh的各条边各帧的二面角和边长
Eigen::MatrixXd Dihs_key;//已知mesh的各条边各帧的二面角
Eigen::MatrixXd Edgs_key;//已知mesh的各条边各帧的边长
Eigen::MatrixXd FaceAreas_key;//已知mesh的各帧各个面的面积
Eigen::MatrixXd Points_key;//已知mesh的各顶点各帧的三维坐标

/*
//int K = (meshNum - 1)*(n_ + 1);//P116页矩阵数组的大小,即共有0-K个mesh，即一共K+1个
//Eigen::SparseMatrix<double> linSysMatrice(K + 1, K + 1);//P116页的矩阵
 */

Eigen::MatrixXd DihEdg_blend;//线性混合已知mesh的各条边各帧的二面角和边长
 //全局变量定义结束*********************************************************************************//

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

	cout << "load mesh..." << endl;
	cout << "calculate dihedral angle、edge length and face area..." << endl;

	//存二面角和边长	
	char *DihEdgDataPath = new char[100];
	sprintf_s(DihEdgDataPath, 100, "Resources\\data\\%s_DihEdgs.txt", MODEL);
	fstream opDE(DihEdgDataPath, ios::out);
	//存顶点三维坐标	
	char *PointsPath = new char[100];
	sprintf_s(PointsPath, 100, "Resources\\data\\%s_Points.txt", MODEL);
	fstream opPoints(PointsPath, ios::out);
	//分别存二面角和边长	
	char *DihDataPath = new char[100];
	sprintf_s(DihDataPath, 100, "Resources\\data\\%s_Dihs.txt", MODEL);
	fstream opD(DihDataPath, ios::out);
	char *EdgDataPath = new char[100];
	sprintf_s(EdgDataPath, 100, "Resources\\data\\%s_Edgs.txt", MODEL);
	fstream opE(EdgDataPath, ios::out);
	/*存面积
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

//降维，2*nE_维到2维
tapkee::DenseMatrix  dimReduction()
{
	const int ROW = 2 * nE_;
	//const int ROW = 3*nV_;
	//const int ROW = nE_;
	const int COL = meshNum;
	tapkee::DenseMatrix matrix_before_dimReduction = tapkee::DenseMatrix::Zero(ROW, COL);

	ifstream infile;
	char *path = new char[100];
	sprintf_s(path, 100, "Resources\\data\\%s_DihEdgs.txt", MODEL);
	//sprintf_s(path, 100, "Resources\\data\\%s_Points.txt", MODEL);
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
		//.withParameters((method = KernelLocalTangentSpaceAlignment,
		.withParameters((method = Isomap,
			num_neighbors = 4,
			target_dimension = 2))
		.embedUsing(matrix_before_dimReduction);
	return output.embedding.transpose();
}

int main(int argc, char *argv[])
{
	getNum_EFV();
	getDihEdgeArea();
	tapkee::DenseMatrix matrix_after_dimReduction = dimReduction();
	//存降维后的坐标	
	char *dimReductionPath = new char[100];
	sprintf_s(dimReductionPath, 100, "Resources\\data\\%s_after_dimReduction.txt", MODEL);
	fstream opDE(dimReductionPath, ios::out);
	opDE << matrix_after_dimReduction << endl;

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

}


