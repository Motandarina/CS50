$(function(){
    $('input:radio').change(function(){
         var c = $('input:radio:checked').val();
         if (c =="substrings")
        {
            $('#length').show();
        }
        else
        {
            $('#length').hide();
        }
    });
});
