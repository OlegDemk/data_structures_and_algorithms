/*
 * pointers.c
 *
 *  Created on: Apr 17, 2021
 *      Author: odemki
 */

// ---------------------------------------------------------------------------
void hello(void)
{
	printf("Hello \n");
}
// ---------------------------------------------------------------------------
void goodbye(void)
{
	printf("Goodbye \n");
}
// ---------------------------------------------------------------------------
pointers_on_functions(void)
{
	void (*message) (void);

	message = hello;
	message();
	message = goodbye;
	message();


	while(1)
	{

	}

}
// ---------------------------------------------------------------------------
