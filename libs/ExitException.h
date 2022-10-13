#ifndef EXIT_EXCEPTION_H
#define EXIT_EXCEPTION_H
class ExitException
{
	public:
		virtual const char * what() const throw()
		{
			return "Exit to Term Signal";
		}
};
#endif
