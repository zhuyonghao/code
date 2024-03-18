#include <string>
#include <array>

class GradeBook
{
public:
	static const size_t students = 10;
	static const size_t tests = 3;
	GradeBook(const std::string&, const std::array<std::array<int, tests>, students>&);
	void setCourseName(const std::string&);
	std::string getCourseName() const;
	void displayMessage() const;
	int getMinimum() const;
	int getMaximum() const;
	double getAverage(const std::array<int, tests>&) const;
	void processGrades() const;
	void outputBarchart() const;
	void outputGrades() const;
private:
	std::string courseName;
	std::array<std::array<int, tests>, students> grades;
};
