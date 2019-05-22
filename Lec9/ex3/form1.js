window.onload=function(){
    let form=document.getElementById("registration")
    form.onsubmit = function() {
        if(!form.email.value)
        {
            alert("email required!");
            return false;
        }
        else if (!form.password.value)
        {
            alert("password required!");
            return false;
        }
        else if(form.confirmation.value=="")
        {
            alert("Please confirm your password!")
            return false;
        }
        else if(form.password.value!=form.confirmation.value)
        {
            alert("Password do not match!")
            return false;
        }
        else if(!form.agreement.checked)
        {
            alert("checkbox not checked!")
            return false;
        }
        return true;
    };
}