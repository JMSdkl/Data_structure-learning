
// ��ʼ����ֵ�������
vector<double> x_fin_values, y_fin_values, z_fin_values, rx_fin_values, ry_fin_values, rz_fin_values;

double sum_distance = 0; //�ȸ�ŷʽ����֮�͸���ֵ0
//�������е�֮���ŷʽ����֮��
for (int i = 1; i < Sel_out_x.size(); ++i)
{
	double distance0 = sqrt(pow(Sel_out_x[i] - Sel_out_x[i - 1], 2) + pow(Sel_out_y[i] - Sel_out_y[i - 1], 2) + pow(Sel_out_z[i] - Sel_out_z[i - 1], 2));
	sum_distance += distance0;
}

// ����ŷʽ������ֵ��������ŷʽ�����ֵ
//double distance_threshold = 2 * sum_distance / Sel_out_x.size();

int distance_threshold = 6;
int distance1_threshold = 4;

int left = 0;
int right = 1;

//��δ����ǽ��пռ��ֵ�����ھ������ĵ��м䲹��һЩ��λ��
// ����Ҫ��ɾ���ĵ���в�ֵ������������ֵ����������ºϲ�
//for (int i = 1; i < Sel_out_x.size(); ++i){
for (; right < Sel_out_x.size(); right++) {

	//double distance = sqrt(pow(Sel_out_x[i] - Sel_out_x[i - 1], 2) + pow(Sel_out_y[i] - Sel_out_y[i - 1], 2) + pow(Sel_out_z[i] - Sel_out_z[i - 1], 2));
	double distance = sqrt(pow(Sel_out_x[right] - Sel_out_x[left], 2) + pow(Sel_out_y[right] - Sel_out_y[left], 2) + pow(Sel_out_z[right] - Sel_out_z[left], 2));

	if (distance > distance_threshold) {
		// �öδ������ڶ���Ҫ��ֵ��������֮����в�ֵ����������һ�������Ĳ�ֵ�㣬������ֵ������ݴ洢���µ�����fin_values��
		x_fin_values.push_back(Sel_out_x[left]);
		y_fin_values.push_back(Sel_out_y[left]);
		z_fin_values.push_back(Sel_out_z[left]);
		rx_fin_values.push_back(Sel_out_Rx[left]);
		ry_fin_values.push_back(Sel_out_Ry[left]);
		rz_fin_values.push_back(Sel_out_Rz[left]);

		// ������Ҫ��ֵ�ĵ���
		int n = ceil(distance / distance_threshold) - 1;

		// ��ֵ����
		double dx = (Sel_out_x[right] - Sel_out_x[left]) / (n + 1);
		double dy = (Sel_out_y[right] - Sel_out_y[left]) / (n + 1);
		double dz = (Sel_out_z[right] - Sel_out_z[left]) / (n + 1);
		double drx = (Sel_out_Rx[right] - Sel_out_Rx[left]) / (n + 1);
		double dry = (Sel_out_Ry[right] - Sel_out_Ry[left]) / (n + 1);
		double drz = (Sel_out_Rz[right] - Sel_out_Rz[left]) / (n + 1);

		for (int j = 0; j < n; ++j) {

			x_fin_values.push_back(Sel_out_x[left] + dx * (