using System;

namespace  MySample
{
    class MyAnimalDelegateClass
    {
        public delegate void DelegateFuntion(string strFuncName);
        private DelegateFuntion m_delegateFunction = null;
        public static void ShowAnimalType()
        {
            
        }
    }

    class LionDelegateClass : MyAnimalDelegateClass
    {

    }
    class HorseDelegateClass : MyAnimalDelegateClass
    {

    }


    
}