
// 初始化插值后的向量
vector<double> x_fin_values, y_fin_values, z_fin_values, rx_fin_values, ry_fin_values, rz_fin_values;

double sum_distance = 0; //先给欧式距离之和赋初值0
//计算所有点之间的欧式距离之和
for (int i = 1; i < Sel_out_x.size(); ++i)
{
	double distance0 = sqrt(pow(Sel_out_x[i] - Sel_out_x[i - 1], 2) + pow(Sel_out_y[i] - Sel_out_y[i - 1], 2) + pow(Sel_out_z[i] - Sel_out_z[i - 1], 2));
	sum_distance += distance0;
}

// 设置欧式距离阈值，三倍的欧式距离均值
//double distance_threshold = 2 * sum_distance / Sel_out_x.size();

int distance_threshold = 6;
int distance1_threshold = 4;

int left = 0;
int right = 1;

//这段代码是进行空间插值，对于距离过大的点中间补上一些点位。
// 对需要被删除的点进行插值操作，并将插值后的数据重新合并
//for (int i = 1; i < Sel_out_x.size(); ++i){
for (; right < Sel_out_x.size(); right++) {

	//double distance = sqrt(pow(Sel_out_x[i] - Sel_out_x[i - 1], 2) + pow(Sel_out_y[i] - Sel_out_y[i - 1], 2) + pow(Sel_out_z[i] - Sel_out_z[i - 1], 2));
	double distance = sqrt(pow(Sel_out_x[right] - Sel_out_x[left], 2) + pow(Sel_out_y[right] - Sel_out_y[left], 2) + pow(Sel_out_z[right] - Sel_out_z[left], 2));

	if (distance > distance_threshold) {
		// 该段代码用于对需要插值的两个点之间进行插值操作，生成一定数量的插值点，并将插值后的数据存储在新的向量fin_values中
		x_fin_values.push_back(Sel_out_x[left]);
		y_fin_values.push_back(Sel_out_y[left]);
		z_fin_values.push_back(Sel_out_z[left]);
		rx_fin_values.push_back(Sel_out_Rx[left]);
		ry_fin_values.push_back(Sel_out_Ry[left]);
		rz_fin_values.push_back(Sel_out_Rz[left]);

		// 计算需要插值的点数
		int n = ceil(distance / distance_threshold) - 1;

		// 插值操作
		double dx = (Sel_out_x[right] - Sel_out_x[left]) / (n + 1);
		double dy = (Sel_out_y[right] - Sel_out_y[left]) / (n + 1);
		double dz = (Sel_out_z[right] - Sel_out_z[left]) / (n + 1);
		double drx = (Sel_out_Rx[right] - Sel_out_Rx[left]) / (n + 1);
		double dry = (Sel_out_Ry[right] - Sel_out_Ry[left]) / (n + 1);
		double drz = (Sel_out_Rz[right] - Sel_out_Rz[left]) / (n + 1);

		for (int j = 0; j < n; ++j) {

			x_fin_values.push_back(Sel_out_x[left] + dx * (