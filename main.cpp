#include <iostream>
#include <cmath>

using namespace std;

const double G = 6.67430e-11;
const double epsilon = 1e5; //softening for the distance

struct Particle {
	double posx, posy, posz;
	double mass;
};

void forces(const Particle& p1, const Particle& p2, double& fx, double& fy, double& fz) {
	double dx = p1.posx - p2.posx;
	double dy = p1.posy - p2.posy;
	double dz = p1.posz - p2.posz;

	double distance = sqrt(dx * dx + dy * dy + dz * dz + epsilon * epsilon);

	double force_magnitude = (G * p1.mass * p2.mass) / (distance* distance);

	fx = force_magnitude * (dx / distance);
	fy = force_magnitude * (dy / distance);
	fz = force_magnitude * (dz / distance);
}

int main() {
	double posx1, posy1, posz1, mass1;
	double posx2, posy2, posz2, mass2;

	cout << "Enter the values of particle 1- " << "\n";
	cout << "X coord: ";
	cin >> posx1;
	cout << "Y coord: ";
	cin >> posy1;
	cout << "Z coord: ";
	cin >> posz1;
	cout << "Mass: ";
	cin >> mass1;

	cout << "\n";

	cout << "Enter the values of particle 2- " << "\n";
	cout << "X coord: ";
	cin >> posx2;
	cout << "Y coord: ";
	cin >> posy2;
	cout << "Z coord: ";
	cin >> posz2;
	cout << "Mass: ";
	cin >> mass2;


	Particle p1 = { posx1, posy1, posz1, mass1};
	Particle p2 = { posx2, posy2, posz2, mass2};

	double fx, fy, fz;
	forces(p1, p2, fx, fy, fz);

	cout << "Forces, on Particle 1, are - (" << fx << "," << fy << "," << fz << ")";

	return 0;
}
