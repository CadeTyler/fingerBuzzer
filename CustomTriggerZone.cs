using UnityEngine;
using System.Collections;
using System.IO.Ports;
 
public class CustomTriggerZone : MonoBehaviour
{
    public string thumb;
    public string index;
    public string middle;
    public string ring;
    public string pinky;

    public SerialPort sp = new SerialPort("COM6",9600);
   

     void Start() {
        OpenConnection();
        thumb = "0";
        index = "0";
        middle = "0";
        ring = "0";
        pinky = "0";
     }

    void OpenConnection() {
         if (sp != null) {
             if (sp.IsOpen) {
                 sp.Close();
             } else {
                 sp.Open();
                 sp.DtrEnable = true;
             }
         }
    }

    void OnTriggerEnter(Collider other)
    {
        //Debug.Log("Detected collision between " + gameObject.name + " and " + other.GetComponent<Collider>().name);
        string thisName = other.GetComponent<Collider>().name;
        if (Equals(thisName, "Hand_Thumb3_CapsuleCollider")) {
            Debug.Log(thisName);
            thumb = "1";
        } else if (Equals(thisName, "Hand_Index3_CapsuleCollider")) {
                        Debug.Log(thisName);
            index = "1";
        } else if (Equals(thisName, "Hand_Middle3_CapsuleCollider")) {
                        Debug.Log(thisName);
            middle = "1";
        } else if (Equals(thisName, "Hand_Ring3_CapsuleCollider")) {
                        Debug.Log(thisName);
            ring = "1";
        } else if (Equals(thisName, "Hand_Pinky3_CapsuleCollider")) {
                        Debug.Log(thisName);
            pinky = "1";
        }
    }

        void OnTriggerExit(Collider other)
    {
        //Debug.Log("Detected collision between " + gameObject.name + " and " + other.GetComponent<Collider>().name);
        string thisName = other.GetComponent<Collider>().name;
        if (Equals(thisName, "Hand_Thumb3_CapsuleCollider")) {
            thumb = "0";
        } else if (Equals(thisName, "Hand_Index3_CapsuleCollider")) {
            index = "0";
        } else if (Equals(thisName, "Hand_Middle3_CapsuleCollider")) {
            middle = "0";
        } else if (Equals(thisName, "Hand_Ring3_CapsuleCollider")) {
            ring = "0";
        } else if (Equals(thisName, "Hand_Pinky3_CapsuleCollider")) {
            pinky = "0";
        }
    }

    void Update() {
        sp.WriteLine("<" + thumb + index + middle + ring + pinky + ">");
        sp.BaseStream.Flush();
    }
}