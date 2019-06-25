#include "func.h"

func::func() : maxVal_(0), minVal_(1) {}

func::~func() {}

func& func::operator<<(const int& x) {
	int y = (*this)[x];
	if (maxVal_ < minVal_)
	{
		maxVal_ = minVal_ = x;
	}
	else if (x > maxVal_)
	{
		maxVal_ = x;
	}
	else if (x < minVal_)
	{
		minVal_ = x;
	}
	fmap_[x] = y;
	return *this;
}

ostream& operator<<(ostream& os, const func& f) {
	f.print(os);
	f.plot(os);
	return os;
}

void func::plot(ostream& os) const {

	vector<int> sortImage;

	sortImage.clear();
	for (auto it : fmap_) { // pushes fmap_ into sortImage
		sortImage.push_back(it.second);
	}
	for (auto it1 = sortImage.begin(); it1 != sortImage.end(); ++it1) {
		for (auto it2 = sortImage.begin(); it2 != it1; ++it2) {
			if (*it1 > *it2) {
				int temp = *it1;
				*it1 = *it2;
				*it2 = temp;
			}
		}
	} // sorts sortImage from large to small

	for (auto it_im = sortImage.begin(); it_im != sortImage.end(); ++it_im) {
		if (it_im != sortImage.begin() && *it_im == *(it_im - 1)) { //remove repeated
			it_im = sortImage.erase(it_im) - 1;
		}
	}

	for (auto it_im = sortImage.begin(); it_im != sortImage.end(); ++it_im) {
		int x_anchor = minVal_;
		if (*it_im < -9)
			os << *it_im;
		else
			if ((*it_im < 0) || (*it_im > 9))
				os << " " << *it_im;
			else
				os << "  " << *it_im;

		for (auto it_dom : fmap_) {
			if (it_dom.second == *it_im) {
				int x = it_dom.first;
				int spaces = x - x_anchor;
				int i = 0;
				while (i < spaces) {
					os << "   ";
					i++;
				}
				os << "*  ";
				x_anchor = x + 1;
			}

		}

		os << endl;
		if ((it_im + 1) != sortImage.end()) { //print empty lines
			int lines = *it_im - *(it_im + 1) - 1;
			int i = 1;

			while (i < lines + 1) {
				if (*it_im - i < -9)
					os << *it_im - i;
				else
					if ((*it_im - i < 0) || (*it_im - i > 9))
						os << " " << *it_im - i;
					else
						os << "  " << *it_im - i;
				os << endl;
				i++;

			}
		}

	}//for sortImage

	//print x axis
	os << " ";
	for (auto i = minVal_; i < maxVal_ + 1; i++) {
		if (i < 0) os << " " << i;
		else os << "  " << i;
	}
	os << endl;
}
