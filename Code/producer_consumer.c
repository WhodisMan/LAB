#include<stdio.h>
void main ()
{
  int buffer[10], bufsize = 5, in, out, pro, cons, choice;
  in = out = 0;
  do
    {
      printf ("\n1)Produce\t2)Consume\t3)Exit\n");
      printf ("Choice ? [1/2/3] >>> ");
      scanf ("%d", &choice);
      switch (choice)
	{
	case 1:
	  if ((in + 1) % bufsize == out)
	    printf ("Buffer is Full\n");
	  else
	    {
	      printf ("Enter Production Value = ");
	      scanf ("%d", &pro);
	      buffer[in] = pro;
	      in = (in + 1) % bufsize;
	    }
	  break;
	case 2:
	  if (in == out)
	    printf ("Buffer is Empty\n");
	  else
	    {
	      cons = buffer[out];
	      printf ("\nConsumed Product = %d\n", cons);
	      out = (out + 1) % bufsize;
	    }
	}
    }
  while (choice != 3);
}
