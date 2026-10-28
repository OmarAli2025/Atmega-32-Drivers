
sint32 Map(sint32 InputValue,
           sint32 InputrangeMin,  sint32 InputrangeMax,
           sint32 OutputrangeMin, sint32 OutputrangeMax)
{
    if(InputrangeMax==InputrangeMin)
    {
        return OutputrangeMin;
    }
    return ((OutputrangeMax-OutputrangeMin)*(InputValue-InputrangeMin)/(InputrangeMax-InputrangeMin)) +OutputrangeMin;
}
