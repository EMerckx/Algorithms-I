template <typename T>
class Lijstknoop;

template <typename T>
class Lijst{
public:
	//...
private:
	Lijstknoop<T>* k;
};

template <typename T>
class Lijstknoop{
	friend class Lijst<T>;
public:
	Lijstknoop(const T &d = T());
private:
	T sl; // sleutel
	Lijst<T> next;
};