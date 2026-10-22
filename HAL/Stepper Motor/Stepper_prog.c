# include "StdLib.h"
# include "ErrorStates.h"
#include "BIT_MATH.h"
#include <util/delay.h>

# include "DIO_interface.h"
#include "Stepper_interface.h"
#include "Stepper_cfg.h"
#include "Stepper_pvt.h"

uint8t StepperMotor_u8Rotate(const StepperConfig_t * copy_pstepperconig,StepperDirection_t copy_stepperDirection,uint16t copy_u16Angle)
{
	uint8t local_u8ErrorState=OK;

	uint16t local_u16Iterations= (uint16t)( ( (uint32t)copy_u16Angle*2048UL)/360UL);

	if(copy_pstepperconig==NULL)
	{
		local_u8ErrorState=NULLPTR;
	}

	else if(copy_stepperDirection!=CW &&copy_stepperDirection!=CCW)
	{
		local_u8ErrorState=NOK;

	}
	else
	{
		for(uint16t local_u16Counter=0;local_u16Counter<=local_u16Iterations;local_u16Counter++)
		{
			if(copy_stepperDirection==CW)
			{

				if(local_u16Counter%4==0)
				{
					DIO_u8SetPinValue(copy_pstepperconig->u8_PortID,copy_pstepperconig->u8_BluePin,DIO_u8LOW);
					DIO_u8SetPinValue(copy_pstepperconig->u8_PortID,copy_pstepperconig->u8_PinkPin,DIO_u8HIGH);
					DIO_u8SetPinValue(copy_pstepperconig->u8_PortID,copy_pstepperconig->u8_OrangePin,DIO_u8HIGH);
					DIO_u8SetPinValue(copy_pstepperconig->u8_PortID,copy_pstepperconig->u8_YellowPin,DIO_u8HIGH);
					_delay_ms(10);
				}

				else if(local_u16Counter%4==1)
				{
					DIO_u8SetPinValue(copy_pstepperconig->u8_PortID,copy_pstepperconig->u8_PinkPin,DIO_u8LOW);
					DIO_u8SetPinValue(copy_pstepperconig->u8_PortID,copy_pstepperconig->u8_BluePin,DIO_u8HIGH);
					DIO_u8SetPinValue(copy_pstepperconig->u8_PortID,copy_pstepperconig->u8_OrangePin,DIO_u8HIGH);
					DIO_u8SetPinValue(copy_pstepperconig->u8_PortID,copy_pstepperconig->u8_YellowPin,DIO_u8HIGH);
					_delay_ms(10);

				}

				else if(local_u16Counter%4==2)
				{

					DIO_u8SetPinValue(copy_pstepperconig->u8_PortID,copy_pstepperconig->u8_YellowPin,DIO_u8LOW);
					DIO_u8SetPinValue(copy_pstepperconig->u8_PortID,copy_pstepperconig->u8_PinkPin,DIO_u8HIGH);
					DIO_u8SetPinValue(copy_pstepperconig->u8_PortID,copy_pstepperconig->u8_OrangePin,DIO_u8HIGH);
					DIO_u8SetPinValue(copy_pstepperconig->u8_PortID,copy_pstepperconig->u8_BluePin,DIO_u8HIGH);
					_delay_ms(10);

				}

				else if(local_u16Counter%4==3)
				{
					DIO_u8SetPinValue(copy_pstepperconig->u8_PortID,copy_pstepperconig->u8_OrangePin,DIO_u8LOW);
					DIO_u8SetPinValue(copy_pstepperconig->u8_PortID,copy_pstepperconig->u8_PinkPin,DIO_u8HIGH);
					DIO_u8SetPinValue(copy_pstepperconig->u8_PortID,copy_pstepperconig->u8_BluePin,DIO_u8HIGH);
					DIO_u8SetPinValue(copy_pstepperconig->u8_PortID,copy_pstepperconig->u8_YellowPin,DIO_u8HIGH);
					_delay_ms(10);


				}


			}
			else if(copy_stepperDirection==CCW)
			{
				if(local_u16Counter%4==0)
				{
					DIO_u8SetPinValue(copy_pstepperconig->u8_PortID,copy_pstepperconig->u8_OrangePin,DIO_u8LOW);
					DIO_u8SetPinValue(copy_pstepperconig->u8_PortID,copy_pstepperconig->u8_PinkPin,DIO_u8HIGH);
					DIO_u8SetPinValue(copy_pstepperconig->u8_PortID,copy_pstepperconig->u8_BluePin,DIO_u8HIGH);
					DIO_u8SetPinValue(copy_pstepperconig->u8_PortID,copy_pstepperconig->u8_YellowPin,DIO_u8HIGH);
					_delay_ms(10);


				}

				else if(local_u16Counter%4==1)
				{
					DIO_u8SetPinValue(copy_pstepperconig->u8_PortID,copy_pstepperconig->u8_YellowPin,DIO_u8LOW);
					DIO_u8SetPinValue(copy_pstepperconig->u8_PortID,copy_pstepperconig->u8_PinkPin,DIO_u8HIGH);
					DIO_u8SetPinValue(copy_pstepperconig->u8_PortID,copy_pstepperconig->u8_OrangePin,DIO_u8HIGH);
					DIO_u8SetPinValue(copy_pstepperconig->u8_PortID,copy_pstepperconig->u8_BluePin,DIO_u8HIGH);
					_delay_ms(10);

				}

				else if(local_u16Counter%4==2)

				{
					DIO_u8SetPinValue(copy_pstepperconig->u8_PortID,copy_pstepperconig->u8_PinkPin,DIO_u8LOW);
					DIO_u8SetPinValue(copy_pstepperconig->u8_PortID,copy_pstepperconig->u8_BluePin,DIO_u8HIGH);
					DIO_u8SetPinValue(copy_pstepperconig->u8_PortID,copy_pstepperconig->u8_OrangePin,DIO_u8HIGH);
					DIO_u8SetPinValue(copy_pstepperconig->u8_PortID,copy_pstepperconig->u8_YellowPin,DIO_u8HIGH);
					_delay_ms(10);

				}
				else if(local_u16Counter%4==3)
				{
					DIO_u8SetPinValue(copy_pstepperconig->u8_PortID,copy_pstepperconig->u8_BluePin,DIO_u8LOW);
					DIO_u8SetPinValue(copy_pstepperconig->u8_PortID,copy_pstepperconig->u8_PinkPin,DIO_u8HIGH);
					DIO_u8SetPinValue(copy_pstepperconig->u8_PortID,copy_pstepperconig->u8_OrangePin,DIO_u8HIGH);
					DIO_u8SetPinValue(copy_pstepperconig->u8_PortID,copy_pstepperconig->u8_YellowPin,DIO_u8HIGH);
					_delay_ms(10);
				}


			}


		}

	}

	return local_u8ErrorState;

}
