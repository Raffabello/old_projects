let user_is_typing = 0;
let user_list = ["Mike", "John", "Bob", "James","Jasper","Jack"];

document.getElementById("search_field").addEventListener("input", () =>{
    /*if(user_is_typing == 0)
    {
        user_is_typing = 1;
        start_animation();
    }
    */
   //if animation exists, do nothing.Wait for timer to stop.
   //if animation doesn't exist play it, start timer.
    if(document.getElementsByClassName("typing-effect-point")[0].style.animation == '')
    {
        start_animation();
        setTimeout(() => {
            stop_animation();
        },3000)
    }
    match_result(document.getElementById("search_field").value, user_list);
});

function stop_animation()
{
    document.getElementById("img_search").style.opacity = "100%";
    document.getElementById("typing-effect").style.opacity = "0%";
    for(let i = 0; i < document.getElementsByClassName("typing-effect-point").length; i ++)
        document.getElementsByClassName("typing-effect-point")[i].style.animation = '';
}

function start_animation()
{
    document.getElementById("img_search").style.opacity = "0%";
    document.getElementById("typing-effect").style.opacity = "100%";
    document.getElementsByClassName("typing-effect-point")[0].style.animation = "typing .4s ease infinite alternate";
    document.getElementsByClassName("typing-effect-point")[1].style.animation = "typing .4s .5s ease infinite alternate";
    document.getElementsByClassName("typing-effect-point")[2].style.animation = "typing .4s 1s ease infinite alternate";   
}

function match_result(text, ls_result)
{
        var result_list = [];
        let tmp_reg = RegExp(text + ".*")   
        let has_result = false
        for(let i = 0; i < ls_result.length; i ++)
        {
            if(tmp_reg.test(ls_result[i]))
                if(result_list.includes(ls_result[i]) == false)
                    result_list.push(ls_result[i])
        }
        if(result_list.length != 0 && text != "") 
            has_result = true
        reload_result(result_list,has_result)

}

function reload_result(result_list, bool)
{
    //execute this piece of code only if text is not empty.
    if(document.getElementById("search_field").value.length != 0)
    {
        if(bool)
        {
            //if list is not empty, remove all the result
            if(document.getElementById("current_search_list").innerHTML != "")
                document.getElementById("current_search_list").innerHTML = "";
            for(let i = 0; i < result_list.length; i++)
                document.getElementById("current_search_list").innerHTML += "<li alt='mention'><span class='user-name'>" + result_list[i] + "</span><br><span class='user-email'>" + result_list[i].toLowerCase() + "@email.com <span class='call-icon'>@</span></li>";
        }
        else
        {
            document.getElementById("current_search_list").innerHTML = "<div id='no-result-div'><img src='./no-results.png' height=40 width=40 style='position:relative;left:50%;transform:translateX(-50%);'/><p id='no-users-found'>No Users found.</p><br><span id='no-users-found-bottom'>Could not find the user.</span></div>"
            stop_animation()
        }
    }
    else
    {
        document.getElementById("current_search_list").innerHTML = ""
        stop_animation();
    }
}

function view_all()
{
    for(let i = 0; i < user_list.length; i++)
        document.getElementById("current_search_list").innerHTML += "<li alt='mention'><span class='user-name'>" + user_list[i] + "</span><br><span class='user-email'>" + user_list[i].toLowerCase() + "@infinicloud.com <span class='call-icon'>@</span></li>";
}

function open_search()
{
    document.getElementById("app-background").style.transform = "scale(1)";
}


function close_search()
{
    document.getElementById("app-background").style.transform = "scale(0)";
}
