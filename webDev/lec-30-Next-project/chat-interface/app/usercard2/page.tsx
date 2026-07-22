import axios from "axios";

export default async function usercard2 () {
  const response = await axios.get("https://week-13-offline.kirattechnologies.workers.dev/api/v1/user/details")

  return(
    <div>
      {response.data.name}
    </div>
  )
 }   